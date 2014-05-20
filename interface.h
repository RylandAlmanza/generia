#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <ncurses.h>
#include "directions.h"

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
    void (*drawString)(char *str, int x, int y, int fg, int bg);
    void (*flush)();
    void (*wipe)();
    void (*uninit)();
};

Display construct_Display();

Point get_delta_from_key(int key);
int get_direction_from_key(int key);

#endif
