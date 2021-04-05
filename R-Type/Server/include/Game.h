#ifndef R_TYPE_GAME_H
#define R_TYPE_GAME_H

#include <string>
#include <GameEntity.h>

class Game {
public:
    std::vector<GameEntity*> entities;

    Game();
};

#endif //R_TYPE_GAME_H
