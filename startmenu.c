#include <stdlib.h>
#include "scene.h"
#include "startmenu.h"
#include "menu.h"
#include "gamescene.h"

Menu start_menu;

void start_game(Display *display) {
    change_scene(&init_game_scene, &update_game_scene, &uninit_game_scene);
    init_scene(display);
}

void quit_game(Display *display) {
    game_over = true;
}

void init_start_menu(Display *display) {
    start_menu = construct_Menu();
    start_menu.addOption(&start_menu, "Start", &start_game);
    start_menu.addOption(&start_menu, "Quit", &quit_game);

    int i;
    for (i = 0; i < start_menu.option_count; i++) {
        display->drawString(start_menu.options[i].label,
                            2,
                            i,
                            WHITE,
                            BLACK);
    }
    display->draw('>', 0, start_menu.selection, WHITE, BLACK);
    display->flush();
}

void update_selection(Display *display, int delta) {
    display->draw(' ', 0, start_menu.selection, WHITE, BLACK);
    start_menu.selection += delta;
    if (start_menu.selection < 0) {
        start_menu.selection = start_menu.option_count - 1;
    }
    if (start_menu.selection >= start_menu.option_count) {
        start_menu.selection = 0;
    }
    display->draw('>', 0, start_menu.selection, WHITE, BLACK);
    display->flush();
}

void update_start_menu(Display *display, int key) {
    if (key == 'j') {
        update_selection(display, 1);
    }
    if (key == 'k') {
        update_selection(display, -1);
    }
    if (key == 'x') {
        start_menu.options[start_menu.selection].callback(display);
    }
}

void uninit_start_menu() {}
