#include "keyutils.h"
#include "directions.h"

Point get_delta_from_key(int key) {
    Point delta = {.x = 0, .y = 0};
    if (key == 38 || key == 'k') {
        delta = directions[NORTH];
    } else if (key == 39 || key == 'l') {
        delta = directions[EAST];
    } else if (key == 40 || key == 'j') {
        delta = directions[SOUTH];
    } else if (key == 37 || key == 'h') {
        delta = directions[WEST];
    }
    return delta;
}

int get_direction_from_key(int key) {
    if (key == 'k') {
        return NORTH;
    }
    if (key == 'l') {
        return EAST;
    }
    if (key == 'j') {
        return SOUTH;
    }
    if (key == 'h') {
        return WEST;
    }
}
