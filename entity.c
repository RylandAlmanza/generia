#include "entity.h"

Entity construct_Entity(char sprite, int x, int y) {
    Entity entity;

    entity.sprite = sprite;
    entity.x = x;
    entity.y = y;

    return entity;
}
