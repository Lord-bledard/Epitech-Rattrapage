#ifndef R_TYPE_RESPONSELISTGAMES_H
#define R_TYPE_RESPONSELISTGAMES_H

#include "Request.h"

struct GameListItem {
    int nbPlayers;
    int capacity;
    char gameName[64];

    GameListItem()
    {

    }

    GameListItem(int nbPlayers, int capacity, const char *gameName)
    {
        this->nbPlayers = nbPlayers;
        this->capacity = capacity;
        strcpy(this->gameName, gameName);
    }
};

struct ResponseListGames : Request {

    int nbGames;
    GameListItem gameList[10];

    ResponseListGames() : Request(RequestType::RESPONSE_LIST_GAME)
    {
        nbGames = 0;
    }
};

#endif //R_TYPE_RESPONSELISTGAMES_H
