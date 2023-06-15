#include "world.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * John Conway's Game of Life in C
 * (ASCII Representation)
 * 
 * This code is by me: Amelia Johnson
*/

unsigned int count_cells(World* world, int row, int col) {
    unsigned int count = 0;

    for (int i = -1; i < 2; i++) {
        if (World_IsInBounds(world, row+1, col+i))
            count++;
        if (World_IsInBounds(world, row-1, col+i))
            count++;
    }

    if (World_IsInBounds(world, row, col+1))
        count++;
    if (World_IsInBounds(world, row, col-1))
        count++;

    return count;
}

void World_ToggleState(World* world, int row, int col) {
    world->world[row][col].alive = !world->world[row][col].alive;
}

World World_New(int rows, int cols) {
    Cell** cells = (Cell**)malloc(sizeof(Cell*)*rows);
    for (int i = 0; i < rows; i++)
        cells[i] = (Cell*)malloc(sizeof(Cell)*cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cells[i][j] = Cell_New(false, i, j);
    
    return (World) {
        .world = cells,
        .rows = rows,
        .cols = cols,
    };
}

World World_Copy(const World* world) {
    World copy = World_New(world->rows, world->cols);

    for (int i = 0; i < world->rows; i++)
        for (int j = 0; j < world->cols; j++) 
            copy.world[i][j] = world->world[i][j];
    
    return copy;    
}

void World_Free(World* world) {
    for (int i = 0; i < world->rows; i++)
        free(world->world[i]);
    free(world->world);
}

bool World_IsInBounds(const World* world, int row, int col) {
    return row < world->rows && row > 0 && col < world->cols && col > 0;
}

Cell* World_GetAdjacentCells(const World* world, int row, int col, int* cellc) {

    int cellCount = count_cells(world, row, col);
    *cellc = cellCount;
    int position = 0;
    Cell* cells = (Cell*)malloc(sizeof(Cell)*cellCount);

     for (int i = -1; i < 2; i++) {
        if (World_IsInBounds(world, row+1, col+i))
           cells[position++] = world->world[row+1][col+i];
        if (World_IsInBounds(world, row-1, col+i))
            cells[position++] = world->world[row-1][col+i];
    }

    if (World_IsInBounds(world, row, col+1))
        cells[position++] = world->world[row][col+1];
    if (World_IsInBounds(world, row, col-1))
        cells[position++] = world->world[row][col-1];

    return cells;
}

void World_Step(World* world) {
    World copy = World_Copy(world);

    for (int i = 0; i < copy.rows; i++)
        for (int j = 0; j < copy.cols; j++) {
            int cellCount = 0;
            Cell* neighbors = World_GetAdjacentCells(&copy, i, j, &cellCount);

            int aliveCount = 0;
            for (int x = 0; x < cellCount; x++)
                if (neighbors[x].alive)
                    aliveCount++;
            
            if (world->world[i][j].alive) {
                if (aliveCount < 2 || aliveCount > 3)
                    world->world[i][j].alive = false;
            } else {
                if (aliveCount == 3)
                    world->world[i][j].alive = true;
            }

            free(neighbors);
        }

    World_Free(&copy);
}

void World_Print(const World* world) {
    for (int i = 0; i < world->rows; i++) {
        for (int j = 0; j < world->cols; j++) {
            if (world->world[i][j].alive) {
                printf(" # ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}