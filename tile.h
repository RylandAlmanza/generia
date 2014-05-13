#ifndef TILE_H_
#define TILE_H_

#include "sprite.h"
#include <stdbool.h>

typedef struct TileStruct Tile;

struct TileStruct {
    Sprite sprite;
    int x;
    int y;
    bool is_solid;
};

Tile construct_Tile(Sprite sprite, int x, int y, bool is_solid);

#endif
