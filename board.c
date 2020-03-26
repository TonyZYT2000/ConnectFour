#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

#define EMPTY '.'
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
        printf("\n");
    }
    for (int col = 0; col < this->width; col++) {
        printf("%d ", col + 1);
    }
}

void clear_Board(Board * this) {
}

void put(Board * this, int col, char chess) {
}

Board * new_Board(int width, int height) {
    Board * this = malloc(sizeof(Board));
    this->win = false;
    this->width = width;
    this->height = height;
    this->checker = malloc(sizeof(char) * width * height);

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            this->checker[INDEX(row, col)] = EMPTY;
        }
    }
    return this;
}

void delete_Board(Board ** toDelete) {
    Board * this = *toDelete;
    free(this->checker);
    free(this);
    *toDelete = NULL;
}
