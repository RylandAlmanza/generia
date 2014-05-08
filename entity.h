#ifndef ENTITY_H_
#define ENTITY_H_

typedef struct EntityS Entity;

struct EntityS {
    char sprite;
    int x;
    int y;
};

Entity construct_Entity(char sprite, int x, int y);

#endif
