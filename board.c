#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

#define GOAL 4
#define EMPTY '.'
#define NEWLINE "\n"
#define INDEX(X, Y) X * this->width + Y

static bool check_Hori(Board * this, int row, int col, char chess);
static bool check_Vert(Board * this, int row, int col, char chess);
static bool check_Diag(Board * this, int row, int col, char chess);

Board * new_Board(int width, int height) {
    Board * this = malloc(sizeof(Board));
    this->win = false;
    this->full = false;
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

void checkwin(Board * this, int colNo) {
    int row = 0;
    int col = colNo - 1;

    while (this->checker[INDEX(row, col)] == EMPTY) {
        row += 1;
    }

    char chess = this->checker[INDEX(row, col)];

    this->win = check_Hori(this, row, col, chess) ||
        check_Vert(this, row, col, chess) ||
        check_Diag(this, row, col, chess);
}

void checkfull(Board * this) {
    int row = 0;

    for (int col = 0; col < this->width; col++) {
        if (this->checker[INDEX(row, col)] == EMPTY) {
            this->full = false;
            return;
        }
    }

    this->full = true;
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

static bool check_Hori(Board * this, int row, int col, char chess) {
    int count = 0;
    int colIndex = (col - GOAL + 1) > 0 ? (col - GOAL + 1) : 0;
    int colLimit = (col + GOAL) < this->width ? (col + GOAL) : this->width;

    while (colIndex < colLimit) {
        if (this->checker[INDEX(row, colIndex)] == chess) {
            count += 1;
        } else {
            count = 0;
        }

        if (count == GOAL) {
            return true;
        }

        colIndex += 1;
    }

    return false;
}

static bool check_Vert(Board * this, int row, int col, char chess) {
    int count = 0;
    int rowIndex = (row + GOAL - 1) < this->height ? 
        (row + GOAL - 1) : (this->height - 1);
    int rowLimit = (row - GOAL) > -1 ? (row - GOAL) : -1;

    while (rowIndex > rowLimit) {
        if (this->checker[INDEX(rowIndex, col)] == chess) {
            count += 1;
        } else {
            count = 0;
        }

        if (count == GOAL) {
            return true;
        }

        rowIndex -= 1;
    }

    return false;
}

static bool check_Diag(Board * this, int row, int col, char chess) {
    int leftCount = 0;
    int rightCount = 0;
    int leftRowIndex;
    int rightRowIndex;

    int rowIndex = (row + GOAL - 1) < this->height ?
        (row + GOAL - 1) : (this->height - 1);
    int rowLimit = (row - GOAL) > -1 ? (row - GOAL) : -1;

    int leftColIndex = (col - GOAL + 1) > 0 ? (col - GOAL + 1) : 0;
    int leftColLimit = (col + GOAL) < this->width ?  (col + GOAL) : this->width;

    int rightColIndex = (col + GOAL - 1) < this->width ?
        (col + GOAL - 1) : (this->width - 1);
    int rightColLimit = (col - GOAL) > -1 ? (col - GOAL) : -1;

    if (rowIndex - row < col - leftColIndex) {
        leftColIndex = col + row - rowIndex;
        leftRowIndex = rowIndex;
    } else {
        leftRowIndex = row + col - leftColIndex;
    }
    
    if (rowIndex - row < rightColIndex - col) {
        rightColIndex = col + rowIndex - row;
        rightRowIndex = rowIndex;
    } else {
        rightRowIndex = row + rightColIndex - col;
    }

    while (leftColIndex < leftColLimit && leftRowIndex > rowLimit) {
        if (this->checker[INDEX(leftRowIndex, leftColIndex)] == chess) {
            leftCount += 1;
        } else {
            leftCount = 0;
        }

        if (leftCount == GOAL) {
            return true;
        }

        leftRowIndex -= 1;
        leftColIndex += 1;
    }

    while (rightColIndex > rightColLimit && rightRowIndex > rowLimit) {
        if (this->checker[INDEX(rightRowIndex, rightColIndex)] == chess) {
            rightCount += 1;
        } else {
            rightCount = 0;
        }

        if (rightCount == GOAL) {
            return true;
        }

        rightRowIndex -= 1;
        rightColIndex -= 1;
    }
    
    return false;
}

