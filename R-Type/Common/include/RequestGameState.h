#ifndef R_TYPE_REQUESTGAMESTATE_H
#define R_TYPE_REQUESTGAMESTATE_H

#include "Request.h"
#include "GameStateItem.h"
#include "GameEntity.h"

struct RequestGameState
{
    int nbItems;
    GameStateItem gameItems[100];

    RequestGameState();
    RequestGameState(std::vector<GameEntity> gameEntities);

};

#endif //R_TYPE_REQUESTGAMESTATE// _H
