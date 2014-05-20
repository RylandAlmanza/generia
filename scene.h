#ifndef SCENE_H_
#define SCENE_H_

#include <stdbool.h>
#include "interface.h"

bool game_over;

void (*init_scene)(Display *display);
void (*update_scene)(Display *display, MEVENT event);
void (*uninit_scene)();
void change_scene(void (*init)(Display *display),
                  void (*update)(Display *display, MEVENT event),
                  void (*uninit)());

#endif
