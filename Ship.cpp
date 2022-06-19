//
// Created by Konrad on 5/27/22.
//

#include "Ship.h"

void Ship::createTexture()
{
    if(texture.loadFromFile("../teksturki/ship_1.png"))
    {
        //std::cout<<"brak pliku statku"<<std::endl;
    }
}
void Ship::createSprite()
{
    sprite.setTexture(this->texture);
    sprite.scale(1.5f, 1.5f);
    sprite.setPosition(900,800);
}
Ship::Ship()
{
    Ship_speed=7.5f;
    bulletcooldown=50;
    currentbulletcooldown=this->bulletcooldown;
    health=100;
    currenthealth=this->health;
    createTexture();
    createSprite();
}
Ship::~Ship()
{
}

float Ship::getShipHealth() const
{
    return health;
}
float Ship::getShipcurrentHealth() const
{
    return currenthealth;
}
void Ship::hitme(int damage)
{
    currenthealth -= damage;
    if(currenthealth<=0)
        currenthealth=0;
}
const bool Ship::canshoot()
{
    if(currentbulletcooldown>=bulletcooldown)
    {
        this->currentbulletcooldown=0;
        return true;
    }
    return false;
}
void Ship::updatebullet()
{
    if(currentbulletcooldown<bulletcooldown)
        currentbulletcooldown += 1;
}
void Ship::update()
{
    updatebullet();
}
void Ship::render(sf::RenderTarget& target)
{
    target.draw(sprite);
}
void Ship::move(const float posX, const float posY) {
    sprite.move(Ship_speed*posX, Ship_speed*posY);
}
const sf::Vector2f & Ship::getPosition() const {
    return sprite.getPosition();
}
const sf::FloatRect Ship::Boundaries() const {
    return sprite.getGlobalBounds();
}

void Ship::setPos(const float x, const float y) {
    sprite.setPosition(x,y);
}

