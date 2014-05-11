#ifndef DIRECTIONS_H_
#define DIRECTIONS_H_

#include "point.h"

static const int NORTH = 0;
static const int EAST = 1;
static const int SOUTH = 2;
static const int WEST = 3;

static const Point directions[] = {
    {.x = 0, .y = -1},
    {.x = 1, .y = 0},
    {.x = 0, .y = 1},
    {.x = -1, .y = 0}
};

#endif
