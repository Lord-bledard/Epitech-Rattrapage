//client

#include <iostream>
#include <boost/asio.hpp>
#include <Request.h>
#include <Menu.h>
#include <Client.h>
#include <Mainframe.h>
#include <ClientActionEnum.h>
#include <RequestClientAction.h>
#include <RequestGameState.h>
#include <Ship.h>
#include <Wall.h>
#include <Monster.h>
#include "ResponseListGames.h"

using boost::asio::ip::udp;


Client::Client()
{

}


void Client::run()
{
    Mainframe mainframe = Mainframe(this);
    mainframe.run();
}

void Client::init()
{

    try
    {
        /* init socket */
        this->io_service = new boost::asio::io_service();
        this->socket = new udp::socket(*io_service, udp::endpoint(udp::v4(), 0));
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}


std::vector<GameEntity*> Client::get_state(ClientActionEnum action)
{
    std::vector<GameEntity*> entities;

    try
    {
        RequestClientAction requestAction = {.action = action};
        size_t s = sizeof(RequestClientAction);

        udp::resolver resolver(*io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
        udp::endpoint server_endpoint = *resolver.resolve(query);

        this->socket->send_to(boost::asio::buffer((char *) &requestAction, s), server_endpoint);

        RequestGameState state;
        this->socket->receive_from(boost::asio::buffer((char *) &state, sizeof(RequestGameState)), server_endpoint);


        for (int i = 0; i < state.nbItems; i++)
        {

            GameStateItem item = state.gameItems[i];

            switch (item.entity)
            {
                case SHIP: {
                    Ship* entity = new Ship();
                    entity->setPosition(item.x, item.y);
                    entities.push_back(entity);
                    break;
                }

                case WALL: {
                    Wall* entity = new Wall();
                    entity->setPosition(item.x, item.y);
                    entities.push_back(entity);
                    break;
                }
                case MONSTER: {
                    Monster* entity = new Monster();
                    entity->setPosition(item.x, item.y);
                    entities.push_back(entity);
                    break;
                }
            }
        }

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return entities;
}
