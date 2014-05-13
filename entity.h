#ifndef ENTITY_H_
#define ENTITY_H_

#undef move

#include "sprite.h"

typedef struct EntityS Entity;

struct EntityS {
    Sprite sprite;
    int x;
    int y;
    int is_facing;
    void (*update)(Entity *self);
    void (*move)(Entity *self, int direction);
};

Entity construct_Entity(Sprite sprite, int x, int y);

#endif
