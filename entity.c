#include "entity.h"

Entity construct_Entity(Sprite sprite, int x, int y) {
    Entity entity;

    entity.sprite = sprite;
    entity.x = x;
    entity.y = y;

    return entity;
}
