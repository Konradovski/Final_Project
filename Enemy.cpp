//
// Created by c on 6/10/22.
//

#include "Enemy.h"

Enemy::Enemy()
{
this->e_health=100;
this->e_currenthealth=this->e_health;

}
Enemy::~Enemy()
{

}

void Enemy::render() {

}

void Enemy::update() {

}
int Enemy::getEnemyHealth() const
{
    return this->e_health;
}
int Enemy::getEnemycurrentHealth() const
{
    return this->e_currenthealth;
}