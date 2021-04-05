
#include <Mainframe.h>
#include <iostream>
#include <Ship.h>
#include <Wall.h>

Mainframe::Mainframe() {}

void Mainframe::run()
{
    int windowWidth = 800;
    int windowHeight = 400;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "R-Type");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    Ship ship = Ship();
    ship.setPosition(40, 60);

    Wall wall1 = Wall();
    Wall wall2 = Wall();
    Wall wall3 = Wall();
    Wall wall4 = Wall();

    wall1.setPosition(0 + 0 * wall1.width, 0);
    wall2.setPosition(0 + 1 * wall1.width, 0);
    wall3.setPosition(0 + 2 * wall1.width, 0);
    wall4.setPosition(0 + 3 * wall1.width, 0);

    this->entities.push_back(ship);
    this->entities.push_back(wall1);
    this->entities.push_back(wall2);
    this->entities.push_back(wall3);
    this->entities.push_back(wall4);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);

        for (auto &entity : entities)
            window.draw(entity.sprite);

        window.display();
    }

}