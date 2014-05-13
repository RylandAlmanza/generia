#include "tile.h"

Tile construct_Tile(Sprite sprite, int x, int y, bool is_solid) {
    Tile tile = {
        .sprite = sprite,
        .x = x,
        .y = y,
        .is_solid = is_solid
    };

    return tile;
}
