#include "world.h"
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
}

World construct_World() {
    World world;

    world.entity_count = 0;
    world.entities = malloc(sizeof(Entity));

    world.addEntity = &World_addEntity;
    world.update = &World_update;
    world.destroy = &World_destroy;

    return world;
}
