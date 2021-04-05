#ifndef R_TYPE_MAINFRAME_H
#define R_TYPE_MAINFRAME_H

#include <SFML/Graphics.hpp>
#include "GameEntity.h"

class Mainframe
{
private:
    std::vector<GameEntity> entities;

public:
    Mainframe();
    void run();

};

#endif //R_TYPE_MAINFRAME_H
