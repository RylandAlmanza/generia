#ifndef MENU_H_
#define MENU_H_

typedef struct MenuOptionStruct MenuOption;

struct MenuOptionStruct {
    char *label;
    void (*callback)();
};

typedef struct MenuStruct Menu;

struct MenuStruct {
    int selection;
    int option_count;
    MenuOption *options;

    void (*addOption)(Menu *self, char *label, void (*callback)());
};

Menu construct_Menu();

#endif
