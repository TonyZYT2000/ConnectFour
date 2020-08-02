#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"


Player * new_Player(char chess, Board * board, int (*move)(Player *)) {
    Player * this = malloc(sizeof(Player));
    this->chess = chess;
    this->board = board;
    this->move = move;

    return this;
}

void delete_Player(Player ** toDelete) {
    Player * this = *toDelete;
    free(this);
    *toDelete = NULL;
}

int human_Move(Player * this) {
    int col = 0;

    printf("Player %c, Please enter a column number: ", this->chess);
    scanf("%d", &col);
    
    while (col < 1 || col > this->board->width) {
        printf("Invalid column number! Please reenter a column number: ");
        scanf("%d", &col);
    }
    
    bool success = put(this->board, col, this->chess);
    while (!success) {
        printf("That col is full!\n");
        printf("Plese reenter a column number: ");
        scanf("%d", &col);

        while (col < 1 || col > this->board->width) {
            printf("Invalid column number! Please reenter a column number: ");
            scanf("%d", &col);
        }
        success = put(this->board, col, this->chess);
    }

    return col;
}

int rand_Move(Player * this) {
    srand(time(0));
    int col = rand() % this->board->width + 1;

    bool success = put(this->board, col, this->chess);
    while (!success) {
        col = rand() % this->board->width + 1;
        success = put(this->board, col, this->chess);
    }

    return col;
}
