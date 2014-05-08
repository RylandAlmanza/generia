#include "world.h"
#include <stdlib.h>

Entity *World_createEntity(World *self) {
    Entity entity = {
        .sprite = '@',
        .x = 0,
        .y = 0
    };

    self->entity_count++;
    self->entities = realloc(self->entities,
                             sizeof(Entity) * (self->entity_count));
    self->entities[self->entity_count - 1] = entity;

    return &self->entities[self->entity_count - 1];
}

World construct_World() {
    World world;

    world.entity_count = 0;
    world.entities = malloc(sizeof(Entity));

    world.createEntity = &World_createEntity;

    return world;
}
