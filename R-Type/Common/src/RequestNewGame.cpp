#include "RequestNewGame.h"

RequestNewGame::RequestNewGame() : Request(), nbPlayers(0)
{}


RequestNewGame::RequestNewGame(int nbPlayers, std::string gameName) :
    Request(RequestType::INIT_GAME),
    nbPlayers(nbPlayers)
{
    strcpy(this->gameName, gameName.c_str());
};
