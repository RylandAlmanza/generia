#include "keyutils.h"

Point get_delta_from_key(int key) {
    Point delta = {.x = 0, .y = 0};
    if (key == 38 || key == 'k') {
        delta = NORTH_DELTA;
    } else if (key == 39 || key == 'l') {
        delta = EAST_DELTA;
    } else if (key == 40 || key == 'j') {
        delta = SOUTH_DELTA;
    } else if (key == 37 || key == 'h') {
        delta = WEST_DELTA;
    }
    return delta;
}
