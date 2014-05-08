#include "display.h"
#include "world.h"

int WORLD_WIDTH;
int WORLD_HEIGHT;
int CAMERA_WIDTH;
int CAMERA_HEIGHT;

int main() {
    Display display = construct_Display();
    display.init();

    World world = construct_World();
    Entity *player = world.createEntity(&world);

    display.draw(player->sprite, player->x, player->y, WHITE, BLACK);
    display.flush();

    int key;
    while (key != 'q') {
        key = getch();
    }

    display.uninit();
}
