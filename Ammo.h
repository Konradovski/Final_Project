//
// Created by Konrad on 09.06.2022.
//

#ifndef MAIN_CPP_AMMO_H
#define MAIN_CPP_AMMO_H

#include<SFML/Graphics.hpp>
#include<iostream>

class Ammo {
    sf::Sprite form;
    sf::Vector2f dir;
    float Bulletspeed;
public:
    Ammo();
    Ammo(sf::Texture& texture, float pos_X, float pos_Y, float Bullet_speed);
    virtual ~Ammo();

    void update();
    void render(sf::RenderTarget *target);

};


#endif //MAIN_CPP_AMMO_H
