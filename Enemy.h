//
// Created by c on 6/10/22.
//

#ifndef SPACE_SHOOTER_ENEMY_H
#define SPACE_SHOOTER_ENEMY_H


class Enemy {
int e_currenthealth;
int e_health;

public:
    Enemy();
    ~Enemy();
    void update();
    void render();

    int getEnemyHealth() const;

    int getEnemycurrentHealth() const;
};


#endif //SPACE_SHOOTER_ENEMY_H
