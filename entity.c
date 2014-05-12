#include "entity.h"

void update_entity(Entity *entity) {}

Entity construct_Entity(Sprite sprite, int x, int y) {
    Entity entity;

    entity.sprite = sprite;
    entity.x = x;
    entity.y = y;

    entity.update = &update_entity;

    return entity;
}
