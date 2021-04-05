#ifndef R_TYPE_SHIP_H
# define R_TYPE_SHIP_H

#include <boost/asio.hpp>
#include <ResponseListGames.h>
#include <SFML/Graphics/Sprite.hpp>
#include "Request.h"
#include "GameEntity.h"

using boost::asio::ip::udp;

class Ship : public GameEntity {

public:
	Ship();
	int _id;
    
};

#endif                 /* !R_TYPE_SHIP_H */