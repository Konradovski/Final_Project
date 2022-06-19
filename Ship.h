//
// Created by Konrad on 5/27/22.
//

#ifndef SPACE_SHOOTER_SHIP_H
#define SPACE_SHOOTER_SHIP_H


#include<SFML/Graphics.hpp>
#include<iostream>

class Ship {

    sf::Sprite sprite;
    sf::Texture texture;

    float bulletcooldown;
    float currentbulletcooldown;
    void createTexture();
    void createSprite();

    float Ship_speed;
public:
    float health; float currenthealth;
    Ship();
    ~Ship();
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect Boundaries() const;

    float getShipHealth() const;
    float getShipcurrentHealth() const;
    const bool canshoot();

    void hitme(int damage);

    void move(const float posX, const float posY);

    void updatebullet();

    void update();

    void render(sf::RenderTarget& target);

    void setPos(const float x, const float y);

};


#endif //SPACE_SHOOTER_SHIP_H
