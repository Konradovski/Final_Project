#include <iostream>
#include "Ship.h"

int main() {
    Ship A(NORMAL,10);
    std::cout<<A.getShipHealth()<<std::endl;
    return 0;
}
