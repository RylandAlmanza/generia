#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "scene.h"
#include "world.h"
#include "entity.h"

World world;
Entity *player;

void init_game_scene(Display *display);
void update_game_scene(Display *display, int key);

#endif
