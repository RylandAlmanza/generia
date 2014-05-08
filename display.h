#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <ncurses.h>

static const int BLACK = COLOR_BLACK;
static const int YELLOW = COLOR_YELLOW;
static const int GREEN = COLOR_GREEN;
static const int BLUE = COLOR_BLUE;
static const int WHITE = COLOR_WHITE;
static const int TRANSPARENT = -1;

typedef struct DisplayStruct Display;

struct DisplayStruct {
    void (*init)();
    void (*draw)(char sprite, int x, int y, int fg, int bg);
    void (*flush)();
    void (*uninit)();
};

Display construct_Display();

#endif
