#include "menu.h"
#include <stdlib.h>

void Menu_addOption(Menu *self, char *label, void (*callback)()) {
    MenuOption option = {
        .label = label,
        .callback = callback
    };

    self->option_count++;
    self->options = realloc(self->options,
                            sizeof(MenuOption) * self->option_count);
    self->options[self->option_count - 1] = option;
}

Menu construct_Menu() {
    Menu menu;
    menu.selection = 0;
    menu.option_count = 0;
    menu.options = malloc(sizeof(MenuOption));

    menu.addOption = &Menu_addOption;

    return menu;
}
