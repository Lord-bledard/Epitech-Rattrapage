#ifndef R_TYPE_MAINFRAME_H
#define R_TYPE_MAINFRAME_H

#include <SFML/Graphics.hpp>
#include "GameEntity.h"
#include "Client.h"

class Mainframe
{
private:
    Client* client;
    std::vector<GameEntity*> entities;

public:
    Mainframe(Client* client);
    void run();

};

#endif //R_TYPE_MAINFRAME_H
