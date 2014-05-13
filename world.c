#include "world.h"
#include "display.h"
#include <stdlib.h>

Entity *World_addEntity(World *self, Entity entity) {
    self->entity_count++;
    self->entities = realloc(self->entities,
                             sizeof(Entity) * (self->entity_count + 1));
    self->entities[self->entity_count - 1] = entity;

    return &self->entities[self->entity_count - 1];
}

void World_update(World *self) {
    int i;
    for (i = 0; i < self->entity_count; i++) {
        self->entities[i].update(&self->entities[i]);
    }
}

void World_destroy(World *self) {
    free(self->entities);
    int y;
    for (y = 0; y < 24; y++) {
        free(self->map[y]);
    }
    free(self->map);
}

World construct_World() {
    World world;

    Sprite grass = {
        .character = '.',
        .fg = GREEN,
        .bg = BLACK,
    };

    world.map = malloc(sizeof(Tile) * (80 * 24));
    int x;
    int y;
    for (y = 0; y < 24; y++) {
        world.map[y] = malloc(sizeof(Tile) * 80);
        for (x = 0; x < 80; x++) {
            world.map[y][x] = construct_Tile(grass, x, y, false);
        }
    }

    world.entity_count = 0;
    world.entities = malloc(sizeof(Entity));

    world.addEntity = &World_addEntity;
    world.update = &World_update;
    world.destroy = &World_destroy;

    return world;
}
