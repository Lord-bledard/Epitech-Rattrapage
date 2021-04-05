#ifndef R_TYPE_GAME_H
# define R_TYPE_GAME_H


#include "Bullet.h"
#include "Ship.h"
#include "Monster.h"
#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include "Request.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics/Texture.hpp>


using boost::asio::ip::udp;

class Game {
private:

public:
    sf::Texture texture;
    sf::Sprite background;
    sf::Text front_promt;
    sf::Text text;
    sf::Font font;
    std::string roomname = "room";
    std::string playername = "player";
    std::vector<Bullet*> bullet;
    std::vector<Monster*> monster;
    std::vector<Ship*> ship;
	Game();
    ~Game();
	void setPlayerName(std::string string);
    int GetMonsterById(int id);
    int GetPlayerById(int id);
	bool MobExist(int id);
    bool PlayerExist(int id);
    void PlayerMvt(sf::Event &event);
    bool GameEndShoot();
    void display();
    void run();
};

#endif                 /* !R_TYPE_CLIENT_H */