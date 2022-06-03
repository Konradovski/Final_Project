#include <iostream>
#include "Ship.h"
#include "Board.h"

int main() {
    Ship A(NORMAL,10);
    Board Board;
    Board.play();
    std::cout<<A.getShipHealth()<<std::endl;
    return 0;
}
