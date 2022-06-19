#include <iostream>
#include "Board.h"
#include <time.h>


int main() {

    srand(static_cast<unsigned int>(time(0)));
    Board Board;
    Board.play();
    return 0;
}
