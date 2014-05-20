#include "gamescene.h"
#include "interface.h"
#include "world.h"
#include "directions.h"
#include "goblin.h"

World world;
Point target;
Entity *player;

void init_game_scene(Display *display) {
    world = construct_World();

    target.x = 0;
    target.y = 0;

    Sprite player_sprite = {
        .character = '@',
        .fg = WHITE,
        .bg = BLACK
    };

    player = world.addEntity(&world, construct_Entity(player_sprite, 1, 1));

    display->wipe();

    int x;
    int y;
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 80; x++) {
            Tile *tile = &world.map[y][x];
            display->draw(tile->sprite.character,
                          tile->x,
                          tile->y,
                          tile->sprite.fg,
                          tile->sprite.bg);
        }
    }

    int i;
    for (i = 0; i < world.entity_count; i++) {
        Entity *entity = &world.entities[i];
        display->draw(entity->sprite.character,
                      entity->x,
                      entity->y,
                      entity->sprite.fg,
                      entity->sprite.bg);
    }
    display->flush();
}

void update_game_scene(Display *display, MEVENT event) {
    if (event.bstate & BUTTON1_PRESSED) {
        target.x = event.x;
        target.y = event.y;
    }
    int i;
    for (i = 0; i < world.entity_count; i++) {
        Entity *entity = &world.entities[i];
        display->draw(world.map[entity->y][entity->x].sprite.character,
                      entity->x,
                      entity->y,
                      world.map[entity->y][entity->x].sprite.fg,
                      world.map[entity->y][entity->x].sprite.bg);
    }
    if (target.x != player->x || target.y != player->y) {
        int direction;
        if (target.y < player->y) {
            direction = NORTH;
        } else if (target.x > player->x) {
            direction = EAST;
        } else if (target.y > player->y) {
            direction = SOUTH;
        } else if (target.x < player->x) {
            direction = WEST;
        }
        player->move(player, direction);
    }

    for (i = 0; i < world.entity_count; i++) {
        Entity *entity = &world.entities[i];
        entity->update(entity);
        if (world.map[entity->y][entity->x].is_solid) {
            entity->move(entity, opposite_directions[entity->is_facing]);
        }
        display->draw(entity->sprite.character,
                      entity->x,
                      entity->y,
                      entity->sprite.fg,
                      entity->sprite.bg);
    }
}

void uninit_game_scene() {
    world.destroy(&world);
}
