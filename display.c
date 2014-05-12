#include "display.h"

int get_color_pair(int fg, int bg) {
    return fg + (bg * 8) + 1;
}

int initialize_all_color_pairs() {
    int fg;
    int bg;
    for (bg = 0; bg < 8; bg++) {
        for (fg = 0; fg < 8; fg++) {
            init_pair(get_color_pair(fg, bg), fg, bg);
        }
    }
}

void Display_init() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    start_color();
    initialize_all_color_pairs();
}

void Display_draw(char sprite, int x, int y, int fg, int bg) {
    int attribute = COLOR_PAIR(get_color_pair(fg, bg));
    attron(attribute);
    mvaddch(y, x, sprite);
    attroff(attribute);
}

void Display_drawString(char *str, int x, int y, int fg, int bg) {
    int attribute = COLOR_PAIR(get_color_pair(fg, bg));
    attron(attribute);
    mvprintw(y, x, str);
    attroff(attribute);
}

void Display_flush() {
    refresh();
}

void Display_wipe() {
    clear();
}

void Display_uninit() {
    curs_set(1);
    endwin();
}

Display construct_Display() {
    Display display;

    display.init = &Display_init;
    display.draw = &Display_draw;
    display.drawString = &Display_drawString;
    display.uninit = &Display_uninit;
    display.flush = &Display_flush;
    display.wipe = &Display_wipe;

    return display;
}
