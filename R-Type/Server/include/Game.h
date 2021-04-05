#ifndef R_TYPE_GAME_H
#define R_TYPE_GAME_H

#include <string>

class Game {

public:
    int nbPlayers;
    int capacity;
    std::string name;

    Game(int capacity, std::string name);
    void start();
};

#endif //R_TYPE_GAME_H
