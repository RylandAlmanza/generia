#ifndef ENTITY_H_
#define ENTITY_H_

#include "sprite.h"

typedef struct EntityS Entity;

struct EntityS {
    Sprite sprite;
    int x;
    int y;
    void (*update)(Entity *self);
};

Entity construct_Entity(Sprite sprite, int x, int y);

#endif
