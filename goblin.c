#include <stdlib.h>
#include "goblin.h"
#include "directions.h"
#include "interface.h"

#undef move

void Goblin_update(Entity *self) {
    int direction = rand() % 4;
    self->move(self, direction);
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
