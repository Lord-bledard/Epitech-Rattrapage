#ifndef R_TYPE_SERVER_H
#define R_TYPE_SERVER_H

#include "Game.h"
#include <list>
#include <iostream>
#include <boost/asio.hpp>
#include "RequestNewGame.h"
#include "Request.h"
#include "GameManager.h"

using boost::asio::ip::udp;

class Server {

private:

    GameManager gameManager;

    boost::asio::io_service *io_service;
    udp::socket *socket;
    udp::endpoint *endpoint;

    void handle_receive(const boost::system::error_code& error, size_t bytes_transferred);
    void handle_request(Request* request);
    void handle_request_init_game(RequestNewGame* request);
    void handle_request_list_games();

    void send_request(Request* request);

public:
    Server();
    void init(int port);
    void run();
    void receive();



};

#endif //R_TYPE_SERVER_H