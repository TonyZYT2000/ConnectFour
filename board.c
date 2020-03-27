#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

#define EMPTY '.'
#define NEWLINE "\n"
#define INDEX(X, Y) X * this->width + Y

typedef struct Board {
    bool win;
    int width;
    int height;
    char* checker;
} Board;

void checkwin(Board * this) {
}

void print_Board(Board * this) {
    for (int row = 0; row < this->height; row++) {
        for (int col = 0; col < this->width; col++) {
            printf("%c ", this->checker[INDEX(row, col)]);
        }
        printf(NEWLINE);
    }
    for (int col = 0; col < this->width; col++) {
        printf("%d ", col + 1);
    }
    printf(NEWLINE);
}

void clear_Board(Board * this) {
    for (int row = 0; row < this->height; row++) {
        for (int col = 0; col < this->width; col++) {
            this->checker[INDEX(row, col)] = EMPTY;
        }
    }
}

bool put(Board * this, int colNo, char chess) {
    int row = 0;
    int col = colNo - 1;
    while (row < this->height) {
        if (this->checker[INDEX(row, col)] != EMPTY)
            break;
        else
            row += 1;
    }

    row -= 1;

    if (row >= 0) {
        this->checker[INDEX(row, col)] = chess;
        return true;
    }
    else
        return false;
}

Board * new_Board(int width, int height) {
    Board * this = malloc(sizeof(Board));
    this->win = false;
    this->width = width;
    this->height = height;
    this->checker = malloc(sizeof(char) * width * height);

    clear_Board(this);

    return this;
}

void delete_Board(Board ** toDelete) {
    Board * this = *toDelete;
    free(this->checker);
    free(this);
    *toDelete = NULL;
}
