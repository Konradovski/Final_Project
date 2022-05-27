//
// Created by c on 5/27/22.
//

#ifndef SPACE_SHOOTER_SHIP_H
#define SPACE_SHOOTER_SHIP_H
enum Gamemode{EASY,NORMAL,HARD};

class Ship {
    Gamemode mode;
int width;
int height;
int health;
public:
    Ship(Gamemode mode, int health);
    int getShipWidth() const ;
    int getShipHeight() const;
    int getShipHealth() const;
};


#endif //SPACE_SHOOTER_SHIP_H
