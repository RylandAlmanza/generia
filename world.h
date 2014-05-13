#ifndef WORLD_H_
#define WORLD_H_

#include "entity.h"
#include "tile.h"

typedef struct WorldStruct World;

struct WorldStruct {
    int entity_count;
    Tile **map;
    Entity *entities;

    Entity *(*addEntity)(World *self, Entity entity);
    void (*update)(World *self);
    void (*destroy)(World *self);
};

World construct_World();

#endif
