#include <Ship.h>

Ship::Ship() : GameEntity("r-typesheet5.gif", sf::IntRect(0, 0, 36, 36), 36, 36)
{

    this->type = EntityEnum::SHIP;
    //sprite.setTexture(texture);
}