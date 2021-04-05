#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include "Game.h"
#include <list>
#include <iostream>
#include <boost/asio.hpp>
#include "RequestNewGame.h"
#include "Request.h"

using boost::asio::ip::udp;

class Server {

private:
    boost::asio::io_service *io_service;
    udp::socket *socket;
    udp::endpoint *endpoint;
    Game gameEngine;

    void receive_client_action();
    void send_game_state();

public:
    Server();
    void init(int port);
    void run();



};

#endif //R_TYPE_SERVER_H