//
// Created by Konrad on 6/10/22.
//

#include "Enemy.h"

Enemy::Enemy(float pos_X,float pos_Y)
{
    exp=rand()% 8 +2;
    dropspeed=static_cast<float>(exp/2);
    enemy_1.setPosition(pos_X,pos_Y);
    enemy_1.setScale(exp/4,exp/4);
    createTexture();
    createSprite();
}
Enemy::~Enemy()
{

}
void Enemy::createTexture()
{
    if(enemy.loadFromFile("../teksturki/asteroid.png"))
    {
        //std::cout<<"brak pliku statku"<<std::endl;
    }
}
void Enemy::createSprite()
{
    enemy_1.setTexture(this->enemy);
    enemy_1.scale(2,2);
}

void Enemy::render(sf::RenderTarget* target) {
target->draw(enemy_1);
}

void Enemy::update() {
    enemy_1.move(0,dropspeed);
}
const sf::FloatRect Enemy::Boundaries() const{
    return enemy_1.getGlobalBounds();
}

 int Enemy::Expcounter() const {
    return exp;
}
