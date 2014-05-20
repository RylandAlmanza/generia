#include "player.h"
#include "interface.h"

void Player_update(Entity *self) {
    if (self->ticks_idle > 30 / 8) {
        if (self->x != self->destination.x ||
            self->y != self->destination.y) {
            self->moveToDestination(self);
            self->ticks_idle = 0;
        }
    } else {
        self->ticks_idle++;
    }
}

Entity construct_Player(int x, int y) {
    Entity player;
    Sprite sprite = {
        .character = '@',
        .fg = WHITE,
        .bg = BLACK
    };
    player = construct_Entity(sprite, x, y);
    player.update = &Player_update;

    return player;
}
