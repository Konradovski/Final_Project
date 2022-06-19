//
// Created by Konrad on 03.06.2022.
//

#ifndef MAIN_CPP_BOARD_H
#define MAIN_CPP_BOARD_H

#include "Ship.h"
#include "Ammo.h"
#include "Enemy.h"
#include <string>
#include<sstream>

class Board {
    sf::Texture Background;
    sf::Font font;
    sf::Text tekst;
    sf::Text durability;
    sf::RectangleShape currenthealth;
    sf::RectangleShape health;
    sf::Text Defeat;
    float CurrentSpawnerTimer;
    float SpawnerTimer;
    sf::RenderWindow* window;
    Ship* ship;
    int exp;
    std::vector<Enemy*> enemies;
    void createWindow();
    void createShip();
    void createTextures();
    void interface();
    void pointcounter();

    sf::Texture* textures;
    std::vector<Ammo*> ammo;
    void Stars();

public:
    Board();

    virtual ~Board();

    void play();

    void render();

    void update();

    void Enemies();

    void createEnemy();
};


#endif //MAIN_CPP_BOARD_H
