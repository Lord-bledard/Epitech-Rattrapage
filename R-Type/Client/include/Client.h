#ifndef R_TYPE_CLIENT_H
# define R_TYPE_CLIENT_H

#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include "Request.h"

using boost::asio::ip::udp;

class Client {
private:

    boost::asio::io_service *io_service;
    udp::socket *socket;
    udp::endpoint *endpoint;

    void create_game_menu();
    void join_game_menu();
    void send_request(Request* request);

    std::vector<GameListItem> get_game_list();
    ResponseListGames receive_response_list_games();
public:
	Client();

    void init();
	void run();



};

#endif                 /* !R_TYPE_CLIENT_H */