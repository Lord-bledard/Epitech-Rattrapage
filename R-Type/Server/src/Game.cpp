#include <iostream>

#include "Game.h"

Game::Game(int capacity, std::string name) :
    nbPlayers(0),
    capacity(capacity),
    name(name)
{
    std::cout << "init game " << this->name << std::endl;
}


void Game::start()
{
    std::cout << "start game in new thread" << std::endl;
}