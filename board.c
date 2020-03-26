#include <stdio.h>
#include "board.h"

typedef struct Board {
    int width;
    int height;
    bool state;
    char** checker;
    void (*put)(int);
    void (*print)(void);
    void (*clear)(void);
    bool (*getstate)(void);
} Board;

void put(int col) {
}

void print(void) {
}

void clear(void) {
}

bool getstate(void) {
}


Board * new_Board(int width, int height) {
}

void delete_Board(Board ** toDelete) {
}
