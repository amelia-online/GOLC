#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "world.h"

/**
 * John Conway's Game of Life in C
 * (ASCII Representation)
 * 
 * This code is by me: Amelia Johnson
*/

int main() {
    World world = World_New(10, 10);

    World_ToggleState(&world, 1, 1);
    World_ToggleState(&world, 2, 2);
    World_ToggleState(&world, 2, 3);
    World_ToggleState(&world, 3, 2);
    World_ToggleState(&world, 1, 3);

    while (1) {
        
        World_Print(&world);
        sleep(1);
        system("clear");
        World_Step(&world);
    }
    World_Free(&world);
}
