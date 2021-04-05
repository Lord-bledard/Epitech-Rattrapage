#ifndef R_TYPE_REQUESTNEWGAME_H
#define R_TYPE_REQUESTNEWGAME_H

#include "Request.h"

struct RequestNewGame : Request {
    RequestNewGame();

    int nbPlayers;
    char gameName[64];

    RequestNewGame(int nbPlayers, std::string gameName);
};


#endif //R_TYPE_REQUESTNEWGAME_H
