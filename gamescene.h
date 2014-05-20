#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "scene.h"

void init_game_scene(Display *display);
void update_game_scene(Display *display, MEVENT event);
void uninit_game_scene();

#endif
