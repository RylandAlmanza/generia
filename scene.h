#ifndef SCENE_H_
#define SCENE_H_

#include <stdbool.h>
#include "display.h"

bool game_over;

void (*init_scene)(Display *display);
void (*update_scene)(Display *display, int key);
void (*uninit_scene)();
void change_scene(void (*init)(Display *display),
                  void (*update)(Display *display, int key),
                  void (*uninit)());

#endif
