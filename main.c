#include "interface.h"
#include "time.h"
#include "scene.h"
#include "startmenu.h"
#include "random.h"
#include <stdio.h>
#include <time.h>

int WORLD_WIDTH;
int WORLD_HEIGHT;
int CAMERA_WIDTH;
int CAMERA_HEIGHT;

Display display;

int main() {
    init_rand();
    game_over = false;
    display = construct_Display();
    display.init();

    change_scene(&init_start_menu, &update_start_menu, &uninit_start_menu);
    init_scene(&display);

    MEVENT event;
    int key;
    while (key != 'q' && game_over == false) {
        key = getch();
        if (key != ERR && key == KEY_MOUSE) {
            getmouse(&event);
        }
        
        update_scene(&display, event);

        usleep(33333);
    }
    uninit_scene();

    display.uninit();
}
