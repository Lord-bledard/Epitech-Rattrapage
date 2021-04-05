#ifndef R_TYPE_BULLET_H
# define R_TYPE_BULLET_H

#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include "Request.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics/Texture.hpp>

using boost::asio::ip::udp;

class Bullet {
private:

public:
	Bullet(sf::Vector2f,int,float,int);
    ~Bullet();
   // int event(sf::Event,sf::RenderWindow *);
    bool display(sf::RenderWindow *, float);
    sf::Texture texture;
    sf::Sprite bullet;
    sf::Vector2f _position;
    int _id;
    sf::Texture _rectTexture;
    sf::RectangleShape _rect;
    float  range;
    int dir = 1;

};

#endif                 /* !R_TYPE_BULLET_H */