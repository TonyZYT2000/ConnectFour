#ifndef BOARD_H
#define LIST_H

typedef struct Board Board;

void checkwin(Board * this);

void print_Board(Board * this);

void clear_Board(Board * this);

void put(Board * this, int col, char chess);

Board * new_Board(int width, int height);

void delete_Board(Board ** toDelete);

#endif
