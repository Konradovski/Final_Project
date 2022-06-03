//
// Created by c on 5/27/22.
//

#ifndef SPACE_SHOOTER_SHIP_H
#define SPACE_SHOOTER_SHIP_H
enum Gamemode{EASY,NORMAL,HARD};

#include<SFML/Graphics.hpp>
#include<iostream>
class Ship {
    Gamemode mode;
    sf::Sprite sprite;
    sf::Texture texture;
    float bulletcooldown;
    float currentbulletcooldown;

int width;
int height;
int health;
int damage;
int currenthealth;
public:
    Ship();
    ~Ship();
    int getShipWidth() const ;
    int getShipHeight() const;
    int getShipHealth() const;
    int getShipcurrentHealth() const;
    const bool canshoot();
    void hitme(int damage);
    void updatebullet();

    void update();

    void render(sf::RenderTarget& target);

    void createTexture();

    void createSprite();
};


#endif //SPACE_SHOOTER_SHIP_H
