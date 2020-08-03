#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef struct Player Player;

struct Player {
    short num;
    char chess;
    Board* board;
    int (*move)(Player *);
};

Player * new_Player(short num, char chess, Board * board, int (*move)(Player *));

void delete_Player(Player ** toDelete);

int human_Move(Player * this);

int rand_Move(Player * this);

#endif
