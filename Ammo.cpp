//
// Created by Konrad on 09.06.2022.
//

#include "Ammo.h"
Ammo::Ammo()
{

}
Ammo::Ammo(sf::Texture* texture, float pos_X, float pos_Y, float move_x, float move_y, float Bullet_speed)
{
    form.setTexture(*texture);
    form.setPosition(pos_X,pos_Y);
    dir.x=move_x;
    dir.y=move_y;
    Bulletspeed = Bullet_speed;
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

const sf::FloatRect Ammo::Boundaries() const {
    return form.getGlobalBounds();
}
