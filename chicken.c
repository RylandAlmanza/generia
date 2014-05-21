#include "random.h"
#include "chicken.h"
#include "directions.h"
#include "interface.h"

#undef move

void Chicken_update(Entity *self) {
    if (self->ticks_idle > 30 / 16) {
        if (self->x == self->destination.x &&
            self->y == self->destination.y) {
            self->destination.x = rand_lim(77) + 1;
            self->destination.y = rand_lim(21) + 1;
        }
        self->moveToDestination(self);
        self->ticks_idle = 0;
    } else {
        self->ticks_idle++;
    }
}

Entity construct_Chicken(int x, int y) {
    Entity chicken;
    Sprite sprite = {
        .character = 'c',
        .fg = WHITE,
        .bg = BLACK
    };
    chicken = construct_Entity(sprite, x, y);
    chicken.update = &Chicken_update;

    return chicken;
}
