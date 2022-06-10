//
// Created by c on 5/27/22.
//

#include "Ship.h"

void Ship::createTexture()
{
    if(texture.loadFromFile("../textures/ship.png"))
    {
        //std::cout<<"brak pliku statku"<<std::endl;
    }
}
void Ship::createSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.15f, 0.15f);
}
Ship::Ship()
{
    Ship_speed=5.f;
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
    health=10;

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

void Ship::move(const float posX, const float posY) {
    sprite.move(this->Ship_speed*posX, this->Ship_speed*posY);
}
