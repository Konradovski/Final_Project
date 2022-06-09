//
// Created by Konrad on 03.06.2022.
//

#ifndef MAIN_CPP_BOARD_H
#define MAIN_CPP_BOARD_H

#include "Ship.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Board {
    sf::RenderWindow* window;
    Ship* ship;
    void createWindow();
    void createShip();
public:
    Board();
    virtual ~Board();
    void play();
    void render();
    void update();
};


#endif //MAIN_CPP_BOARD_H
