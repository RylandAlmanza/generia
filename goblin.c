#include <stdlib.h>
#include "goblin.h"
#include "directions.h"
#include "display.h"

void Goblin_update(Entity *self) {
    Point direction = directions[rand() % 4];
    self->x += direction.x;
    self->y += direction.y;
}

Entity construct_Goblin(int x, int y) {
    Entity goblin;
    Sprite sprite = {
        .character = 'g',
        .fg = GREEN,
        .bg = BLACK
    };
    goblin.sprite = sprite;
    goblin.x = x;
    goblin.y = y;
    goblin.update = &Goblin_update;

    return goblin;
}
