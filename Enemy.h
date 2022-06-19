//
// Created by Konrad on 6/10/22.
//

#ifndef SPACE_SHOOTER_ENEMY_H
#define SPACE_SHOOTER_ENEMY_H

#include<SFML/Graphics.hpp>
class Enemy {
int exp;
sf::Texture enemy;
sf::Sprite enemy_1;
float dropspeed;
void createTexture();
void createSprite();
public:
    Enemy(float pos_X,float pos_Y);

    ~Enemy();

    void update();

    void render(sf::RenderTarget* target);

    const sf::FloatRect Boundaries() const;

    int Expcounter() const;

};


#endif //SPACE_SHOOTER_ENEMY_H
