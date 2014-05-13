#include "gamescene.h"
#include "keyutils.h"
#include "world.h"

World world;
Entity *player;

void init_game_scene(Display *display) {
    world = construct_World();

    Sprite player_sprite = {
        .character = '@',
        .fg = WHITE,
        .bg = BLACK,
    };

    player = world.addEntity(&world, construct_Entity(player_sprite, 0, 0));

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

void update_game_scene(Display *display, int key) {
    int i;
    for (i = 0; i < world.entity_count; i++) {
        Entity *entity = &world.entities[i];
        display->draw(world.map[entity->y][entity->x].sprite.character,
                      entity->x,
                      entity->y,
                      world.map[entity->y][entity->x].sprite.fg,
                      world.map[entity->y][entity->x].sprite.bg);
    }
    if (key == 'h' || key == 'j' || key == 'k' || key == 'l') {
        Point delta = get_delta_from_key(key);
        player->x += delta.x;
        player->y += delta.y;
    }

    for (i = 0; i < world.entity_count; i++) {
        Entity *entity = &world.entities[i];
        entity->update(entity);
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
