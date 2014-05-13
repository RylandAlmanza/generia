#include "entity.h"
#include "directions.h"

void update_Entity(Entity *self) {}

void move_Entity(Entity *self, int direction) {
    self->x += directions[direction].x;
    self->y += directions[direction].y;
    self->is_facing = direction;
}

Entity construct_Entity(Sprite sprite, int x, int y) {
    Entity entity;

    entity.sprite = sprite;
    entity.x = x;
    entity.y = y;
    entity.is_facing = NORTH;

    entity.update = &update_Entity;
    entity.move = &move_Entity;

    return entity;
}
