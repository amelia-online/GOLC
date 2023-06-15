#ifndef WORLD_H_
#define WORLD_H_

/**
 * John Conway's Game of Life in C
 * (ASCII Representation)
 * 
 * This code is by me: Amelia Johnson
*/

#include "cell.h"

typedef struct {

    Cell** world;
    int rows;
    int cols;

} World;

World World_New(int, int);
World World_Copy(const World*);
Cell* World_GetAdjacentCells(const World*, int, int, int*);
bool World_IsInBounds(const World*, int, int);
void World_Step(World*);
void World_Print(const World*);
void World_ToggleState(World*, int, int);
void World_Free(World*);

#endif // WORLD_H_