#include "random.h"
#include "goblin.h"
#include "directions.h"
#include "interface.h"

#undef move

void Goblin_update(Entity *self) {
    if (self->ticks_idle > 30 / 4) {
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

Entity construct_Goblin(int x, int y) {
    Entity goblin;
    Sprite sprite = {
        .character = 'g',
        .fg = GREEN,
        .bg = BLACK
    };
    goblin = construct_Entity(sprite, x, y);
    goblin.update = &Goblin_update;

    return goblin;
}
