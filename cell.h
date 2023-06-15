#ifndef CELL_H_
#define CELL_H_

/**
 * John Conway's Game of Life in C
 * (ASCII Representation)
 * 
 * This code is by me: Amelia Johnson
*/

#include <stdbool.h>

typedef struct {
    int row;
    int col;
    bool alive;
} Cell;

Cell Cell_New(bool, int, int);

#endif // CELL_H_