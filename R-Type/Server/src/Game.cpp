#include <iostream>
#include "Ship.h"
#include "Wall.h"

#include "Game.h"

Game::Game()
{
    std::cout << "init game " << std::endl;

    Ship* ship = new Ship();
    ship->setPosition(40, 60);

    Wall* wall1 = new Wall();
    Wall* wall2 = new Wall();
    Wall* wall3 = new Wall();
    Wall* wall4 = new Wall();
    Wall* wall5 = new Wall();
    Wall* wall6 = new Wall();

    Wall* wall7 = new Wall();
    Wall* wall8 = new Wall();
    Wall* wall9 = new Wall();
    Wall* wall10 = new Wall();
    Wall* wall11 = new Wall();
    Wall* wall12 = new Wall();

    wall1->setPosition(0 + 0 * wall1->width, 0);
    wall2->setPosition(0 + 1 * wall1->width, 0);
    wall3->setPosition(0 + 2 * wall1->width, 0);
    wall4->setPosition(0 + 3 * wall1->width, 0);
    wall5->setPosition(0 + 4 * wall1->width, 0);
    wall6->setPosition(0 + 5 * wall1->width, 0);

    wall7->setPosition(0 + 0 * wall1->width, 348);
    wall8->setPosition(0 + 1 * wall1->width, 348);
    wall9->setPosition(0 + 2 * wall1->width, 348);
    wall10->setPosition(0 + 3 * wall1->width, 348);
    wall11->setPosition(0 + 4 * wall1->width, 348);
    wall12->setPosition(0 + 5 * wall1->width, 348);

    this->entities.push_back(ship);
    this->entities.push_back(wall1);
    this->entities.push_back(wall2);
    this->entities.push_back(wall3);
    this->entities.push_back(wall4);
    this->entities.push_back(wall5);
    this->entities.push_back(wall6);
    this->entities.push_back(wall7);
    this->entities.push_back(wall8);
    this->entities.push_back(wall9);
    this->entities.push_back(wall10);
    this->entities.push_back(wall11);
    this->entities.push_back(wall12);

    for (int i = 0; i < this->entities.size(); i++)
    {
        GameEntity* entity = this->entities[i];

        std::cout << "type : " << entity->type;
        std::cout << " x : " << entity->x;
        std::cout << " y : " << entity->y;
        std::cout << std::endl;
    }


}
