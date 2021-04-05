#include "GameEntity.h"
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

GameEntity::GameEntity(std::string filename, sf::IntRect rect, int width, int height)
{
    this->type = EntityEnum::OBJECT;
    this->width = width;
    this->height = height;

    std::string test = "../../Client/rTypeSheet/" + filename;

    if (!texture.loadFromFile(test, rect))
    {
        std::cout << "erreur" << std::endl;
    }

    sprite.setTexture(texture);

}

void GameEntity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
    this->sprite.setPosition(x, y);
}
