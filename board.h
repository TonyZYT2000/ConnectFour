#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

typedef struct Board {
    bool win;
    int width;
    int height;
    char* checker;
} Board;

void checkwin(Board * this, int colNo);

void print_Board(Board * this);

void clear_Board(Board * this);

bool put(Board * this, int colNo, char chess);

Board * new_Board(int width, int height);

void delete_Board(Board ** toDelete);

#endif
