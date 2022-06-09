//
// Created by Konrad on 09.06.2022.
//

#include "Ammo.h"
Ammo::Ammo()
{

}
Ammo::Ammo(sf::Texture& texture, float pos_X, float pos_Y, float Bullet_speed)
{
    form.setTexture(texture);
    this->dir.x=pos_X;
    this->dir.y=pos_Y;
    this->Bulletspeed = Bullet_speed;
}

Ammo::~Ammo()
{

}

void Ammo::update() {
    form.move(Bulletspeed*dir );
}

void Ammo::render(sf::RenderTarget *target) {
    target->draw(form);
}
