//client

#include <iostream>
#include <boost/asio.hpp>
#include <Request.h>
#include <Menu.h>
#include <Client.h>
#include <Mainframe.h>
#include "ResponseListGames.h"
#include "RequestNewGame.h"

using boost::asio::ip::udp;

#define RETURN 0

Client::Client()
{

}

void Client::create_game_menu()
{

    Menu numPlayersMenu = Menu("How many players ?",
                               {"return", "1 player", "2 players", "3 players", "4 players"});

    int selection = numPlayersMenu.getSelectedOption();

    if (selection == RETURN)
    {
        std::cout << "return" << std::endl;
        return;
    }

    int nbPlayers = selection;

    std::string gameName;

    std::cout << "Choose a name for your game : ";
    std::cin >> gameName;

    Request req = RequestNewGame(nbPlayers, gameName);

    this->send_request(&req);

    std::cout << "Game created : " << gameName << std::endl << std::endl;

}

void Client::join_game_menu()
{

    std::vector<GameListItem> gameList = this->get_game_list();

    std::vector<std::string> options = {"return"};

    for (auto &item : gameList)
    {
        std::string option = std::string(item.gameName) + " - " + std::to_string(item.nbPlayers)+ "/" + std::to_string(item.capacity);

        options.push_back(option);
    }

    Menu joinGameMenu = Menu("What game do you want to join ?", options);

    int selection = joinGameMenu.getSelectedOption();

    if (selection == RETURN)
        return;

    std::string gameName = gameList[selection - 1].gameName;

    //TODO send request
    std::cout << "join game " << gameName << std::endl;
}

void play()
{
    Mainframe mainframe = Mainframe();
    mainframe.run();
    std::cout << "Exit game" << std::endl;
}



void Client::run()
{

    Menu mainMenu = Menu("What do you want to do ?",
                         {"Start new game", "Join existing game", "Play", "Exit"});

    enum options {NEW_GAME, JOIN_GAME, PLAY, EXIT};

    int exit = 0;

    while(!exit)
    {
        switch(mainMenu.getSelectedOption())
        {
            case NEW_GAME:
                create_game_menu();
                break;
            case JOIN_GAME:
                join_game_menu();
                break;
            case PLAY:
                play();
            case EXIT:
                exit = 1;
                break;
        }
    }
}

void Client::init()
{

    /* init boost asio service */
    this->io_service = new boost::asio::io_service();

    /* connect to server */
    udp::resolver resolver(*io_service);
    udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
    udp::endpoint endpoint_ = *resolver.resolve(query);
    endpoint = &endpoint_;

    /* init socket */
    this->socket = new udp::socket (*io_service, udp::endpoint(udp::v4(), 0));

    /*
    Request req = Request(RequestType::STOP);
    std::cout << "request type : " << req.type << std::endl;
    this->socket->send_to(boost::asio::buffer(&req, sizeof(Request)), *endpoint);
     */
}

void Client::send_request(Request* request)
{
    size_t s;

    switch (request->type) {
        case RequestType::INIT_GAME:
            s = sizeof(RequestNewGame);
            break;
        case RequestType::LIST_GAMES:
            s = sizeof(Request);
        default: {
            break;
        }
    }

    socket->send_to(boost::asio::buffer((char *) request, s), *endpoint);
}

ResponseListGames Client::receive_response_list_games()
{
    ResponseListGames response;
    size_t len = this->socket->receive_from(boost::asio::buffer(&response, sizeof(ResponseListGames)), *endpoint);
    /* todo error checking */
    return response;
}

std::vector<GameListItem> Client::get_game_list()
{
    /* Ask server for game list */
    Request request(RequestType::LIST_GAMES);
    this->send_request(&request);

    /* Wait for response */
    ResponseListGames response = this->receive_response_list_games();

    /* build vector from message */
    std::vector<GameListItem> gameList = std::vector<GameListItem>();
    for (int i = 0; i < response.nbGames; i++)
    {
        gameList.push_back(response.gameList[i]);
    }

    return gameList;
}
