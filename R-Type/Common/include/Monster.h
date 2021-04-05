#ifndef R_TYPE_MONSTER_H
#define R_TYPE_MONSTER_H

#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include "Request.h"
#include "GameEntity.h"

using boost::asio::ip::udp;

class Monster : public GameEntity {

bool dir;
public:
	Monster();
	bool goingUp();
	bool goingDown();
	void changeDirection();
};

#endif                 /* !R_TYPE_MONSTER_H */