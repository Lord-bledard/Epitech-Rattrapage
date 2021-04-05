#include "Game.h"

bool Game::MobExist(int id) {

    for (unsigned int i = 0; i < monster.size(); i++) {
        if (monster[i] && monster[i]->_id == id)
            return (true);
    }
    return (false);
}

bool Game::PlayerExist(int id) {

    for (unsigned int i = 0; i < ship.size(); i++) {
        if (ship[i] && ship[i]->_id == id)
            return (true);
    }
    return (false);
}

int Game::GetMonsterById(int id) {
    for (unsigned int i = 0; i < monster.size(); i++) {
        if (monster[i] && monster[i]->_id == id)
            return (i);
    }
    return (-1);
}

int Game::GetPlayerById(int id) {
    for (unsigned int i = 0; i < ship.size(); i++) {
        if (ship[i] && ship[i]->_id == id)
            return (i);
    }
    return (-1);
}

void Game::run()
{

}

void Game::PlayerMvt(sf::Event &event)
{
	switch (event.key.code) {
		case sf::Keyboard::Z :
			//up
			break;
		case sf::Keyboard::Q :
			//left
			break;
		case sf::Keyboard::S :
			//down
			break;
		case sf::Keyboard::D :
			//right
			break;
		default :
			break;
	}
}

bool Game::GameEndShoot()
{
    sf::Event event;

		if (event.type == sf::Event::Closed) {
			return false;
		}
		if (event.type == sf::Event::KeyPressed)
        {
			PlayerMvt(event);
            return true;
        }
		if (event.type == sf::Event::KeyReleased &&
			event.key.code == sf::Keyboard::Space)
            {
            return true;
			//shoot
			
	}
}