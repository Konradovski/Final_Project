//
// Created by c on 5/27/22.
//

#include "Ship.h"
#include <iostream>
void Ship::createTexture()
{
    //tu bedzie ladowanie texture
}
void Ship::createSprite()
{
    this->sprite.setTexture(this->texture);
    // tu bedzie zmienianie textury
}
Ship::Ship()
{
    this->bulletcooldown=100;
    this->currentbulletcooldown=this->bulletcooldown;
    this->health=1000;
    this->currenthealth=this->health;
    this->mode=mode;
    this->createTexture();
    this->createSprite();
}
Ship::~Ship()
{

}
int Ship::getShipHeight() const
{
    return height;
}
int Ship::getShipWidth() const
{
    return width;
}
int Ship::getShipHealth() const
{
    return this->health;
}
int Ship::getShipcurrentHealth() const
{
    return this->currenthealth;
}
void Ship::hitme(int damage)
{
    this->health -= damage;
    if(this->health<=0)
        this->health=0;
}
const bool Ship::canshoot()
{
    if(this->currentbulletcooldown>=this->bulletcooldown)
    {
        this->currentbulletcooldown=0;
        return true;
    }
    return false;
}
void Ship::updatebullet()
{
    if(this->currentbulletcooldown<this->bulletcooldown)
        this->currentbulletcooldown += 25;
}
void Ship::update()
{
    updatebullet();
}
void Ship::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}
