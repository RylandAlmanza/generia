#include "display.h"
#include "time.h"
#include "scene.h"
#include "startmenu.h"
#include <stdlib.h>
#include <stdio.h>

int WORLD_WIDTH;
int WORLD_HEIGHT;
int CAMERA_WIDTH;
int CAMERA_HEIGHT;

Display display;

int main() {
    game_over = false;
    display = construct_Display();
    display.init();

    change_scene(&init_start_menu, &update_start_menu);
    init_scene(&display);

    int key;
    while (key != 'q' && game_over == false) {
        key = getch();
        if (key == ERR) {
            key = 0;
        }
        
        update_scene(&display, key);

        usleep(33333);
    }

    display.uninit();
}
