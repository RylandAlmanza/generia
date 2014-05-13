#include "scene.h"

void change_scene(void (*init)(Display *display),
                  void (*update)(Display *display, int key),
                  void (*uninit)()) {
    init_scene = init;
    update_scene = update;
    uninit_scene = uninit;
}
