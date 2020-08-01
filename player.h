#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef struct Player {
    char* chess;
    Board* board;
    void (*move)(Player *);
} Player;

Player * new_Player(Board * board, void (*move)(Player *));

void human_Move(Player * this);

#endif
