#include "entity.h"
#include "directions.h"

void Entity_update(Entity *self) {
    self->ticks_idle++;
}

void Entity_move(Entity *self, int direction) {
    self->x += directions[direction].x;
    self->y += directions[direction].y;
    self->is_facing = direction;
}

void Entity_moveToDestination(Entity *self) {
    int direction;
    if (self->destination.y < self->y) {
        direction = NORTH;
    } else if (self->destination.x > self->x) {
        direction = EAST;
    } else if (self->destination.y > self->y) {
        direction = SOUTH;
    } else if (self->destination.x < self->x) {
        direction = WEST;
    }
    self->move(self, direction);
}

Entity construct_Entity(Sprite sprite, int x, int y) {
    Entity entity;
    Point destination = {
        .x = x,
        .y = y
    };

    entity.sprite = sprite;
    entity.x = x;
    entity.y = y;
    entity.is_facing = NORTH;
    entity.ticks_idle = 0;
    entity.destination = destination;

    entity.update = &Entity_update;
    entity.move = &Entity_move;
    entity.moveToDestination = &Entity_moveToDestination;

    return entity;
}
