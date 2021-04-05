//server

#include <iostream>
#include "Server.h"
#include "GameManager.h"
#include <boost/bind.hpp>
#include "ResponseListGames.h"

using boost::asio::ip::udp;


Server::Server()
{
    this->gameManager = GameManager();
    std::cout << "create server" << std::endl;
}

void Server::run()
{

    this->gameManager.start_new_game(3, "DefaultGame");

    this->receive();
    this->io_service->run();

    std::cout << "shutting down..." << std::endl;
}

void Server::init(int port)
{
    this->io_service = new boost::asio::io_service();

    endpoint = new udp::endpoint(udp::v4(), port);
    this->socket = new udp::socket (*io_service, *endpoint);

}

void Server::handle_request_init_game(RequestNewGame* request)
{
    this->gameManager.start_new_game(request->nbPlayers, request->gameName);
}

void Server::handle_request(Request* request)
{
    switch (request->type)
    {
        case RequestType::INIT_GAME:
        {
            this->handle_request_init_game((RequestNewGame *) request);
            break;
        }
        case RequestType::LIST_GAMES:
        {
            this->handle_request_list_games();
            break;
        }
        default:
            break;

    }
}

void Server::handle_receive(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::cout << "Receive" << std::endl;

    if (error == boost::asio::error::operation_aborted)
    {
        std::cout << "Receive but error : " << error << std::endl;
        return;
    }

    /* Check data size available on socket */
    unsigned int available = this->socket->available();
    std::cout << "available : " << available << std::endl;

    /* Prepare buffer and fill it */
    unsigned char* buffer = new unsigned char[available];
    boost::system::error_code ec;
    unsigned int packetSize = this->socket->receive_from(boost::asio::buffer(buffer, available), *endpoint, 0, ec);
    std::cout << "packetsize : " << packetSize << std::endl;

    /* error checking */
    if (ec)
        std::cout << "error : " << ec << std::endl;


    Request *req = (Request*) buffer;
    std::cout << "request type : " << req->type << std::endl;

    this->handle_request((Request*) buffer);

    /* switch to receive mode again */
    this->receive();
}


void Server::receive()
{
    std::cout << "waiting for receive..." << std::endl;

    /* call 'RequestManager::handle_receive' when request is received */
    socket->async_receive(boost::asio::null_buffers(),
                          boost::bind(&Server::handle_receive, this,
                                      boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Server::send_request(Request* request)
{
    size_t s;

    switch (request->type)
    {
        case RequestType::RESPONSE_LIST_GAME: {
            s = sizeof(ResponseListGames);

            ResponseListGames* test = (ResponseListGames*) request;
            std::cout << test->gameList[0].gameName << std::endl;
            std::cout << test->gameList[1].gameName << std::endl;
            std::cout << s << std::endl;
            break;
        }
        default:
            break;
    }

    std::cout << "send request of type " << request->type << std::endl;

    socket->send_to(boost::asio::buffer((char *) request, s), *endpoint);
}


void Server::handle_request_list_games()
{
    ResponseListGames responseGameList = ResponseListGames();

    std::vector<GameListItem> gameList = this->gameManager.get_game_list();

    responseGameList.nbGames = gameList.size();

    for (int i = 0; i < gameList.size(); i++)
    {
        responseGameList.gameList[i] = gameList[i];
    }

    this->send_request(&responseGameList);
}


