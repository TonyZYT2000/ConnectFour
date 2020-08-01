#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef struct Player {
    char chess;
    Board* board;
    void (*move)(void *);
} Player;

Player * new_Player(char chess, Board * board, void (*move)(void *));

void human_Move(void * this);

#endif
