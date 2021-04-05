//server

#include <iostream>
#include "Server.h"
#include <boost/bind.hpp>
#include <Ship.h>
#include "RequestClientAction.h"
#include "RequestGameState.h"
#include "ResponseListGames.h"
#include "Game.h"

using boost::asio::ip::udp;

Server::Server()
{
    std::cout << "create server" << std::endl;
    gameEngine = Game();
}

void Server::run()
{


    while (true)
    {
        this->receive_client_action();
        this->send_game_state();
    }
}


void Server::init(int port)
{

    this->io_service = new boost::asio::io_context();
    this->socket = new udp::socket (*io_service, udp::endpoint(udp::v4(), 9999));

    this->endpoint = new udp::endpoint();

}

void Server::receive_client_action()
{
    RequestClientAction request;
    this->socket->receive_from(boost::asio::buffer(&request, sizeof(RequestClientAction)), *endpoint);

    int speed = 2;
    switch (request.action)
    {
        case ClientActionEnum::IDLE:
            std::cout << "IDLE" << std::endl;
            break;
        case ClientActionEnum::UP: {
            std::cout << "UP" << std::endl;
            Ship *ship = (Ship *) this->gameEngine.entities[0];
            int x = ship->x;
            int y = ship->y;
            ship->setPosition(x, y - speed);
            break;
        }
        case ClientActionEnum::DOWN: {
            std::cout << "DOWN" << std::endl;

            Ship *ship = (Ship *) this->gameEngine.entities[0];
            int x = ship->x;
            int y = ship->y;
            ship->setPosition(x, y + speed);
            break;
        }
        case ClientActionEnum::LEFT: {
            std::cout << "LEFT" << std::endl;

            Ship *ship = (Ship *) this->gameEngine.entities[0];
            int x = ship->x;
            int y = ship->y;
            ship->setPosition(x - speed, y);
            break;
        }
        case ClientActionEnum::RIGHT:
            std::cout << "RIGHT" << std::endl;

            Ship *ship = (Ship *) this->gameEngine.entities[0];
            int x = ship->x;
            int y = ship->y;
            ship->setPosition(x + speed, y);
            break;
    }
}

void Server::send_game_state()
{

    RequestGameState request;

    for (int i = 0; i < this->gameEngine.entities.size(); i++)
    {
        GameEntity* entity = this->gameEngine.entities[i];
        request.gameItems[i] = {.entity = entity->type, .x = entity->x, .y = entity->y};
        std::cout << "type : " << entity->type;
        std::cout << " x : " << entity->x;
        std::cout << " y : " << entity->y;
        std::cout << std::endl;
    }

    request.nbItems = this->gameEngine.entities.size();
    this-socket->send_to(boost::asio::buffer(&request, sizeof(RequestGameState)), *endpoint);
}

