#include "Monster.h"

Monster::Monster() : GameEntity("r-typesheet24.gif", sf::IntRect(0, 0, 66, 66), 66, 66)
{
    this->type = EntityEnum::MONSTER;
    this->dir = 1;
}

bool Monster::goingUp()
{
    return this->dir;
}

bool Monster::goingDown()
{
    return !this->dir;
}

void Monster::changeDirection()
{
    this->dir = !dir;
}