#include "cell.h"

/**
 * John Conway's Game of Life in C
 * (ASCII Representation)
 * 
 * This code is by me: Amelia Johnson
*/

Cell Cell_New(bool alive, int row, int col) {
    return (Cell) {
        .alive = alive,
        .row = row,
        .col = col,
    };
}
