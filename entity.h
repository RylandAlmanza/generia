#ifndef ENTITY_H_
#define ENTITY_H_

#undef move

#include "sprite.h"
#include "point.h"

typedef struct EntityS Entity;

struct EntityS {
    Sprite sprite;
    int x;
    int y;
    int is_facing;
    int ticks_idle;
    Point destination;
    void (*update)(Entity *self);
    void (*move)(Entity *self, int direction);
    void (*moveToDestination)(Entity *self);
};

Entity construct_Entity(Sprite sprite, int x, int y);

#endif
