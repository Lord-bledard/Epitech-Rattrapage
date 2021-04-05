#ifndef R_TYPE_GAMEENTITY_H
#define R_TYPE_GAMEENTITY_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameEntity
{
public:
    sf::Sprite sprite;
    sf::Texture texture;

    int width;
    int height;

    GameEntity(std::string filename, sf::IntRect rect, int width, int height);
    void setPosition(int x, int y);
};

#endif //R_TYPE_GAMEENTITY_H
