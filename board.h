#ifndef BOARD_H
#define LIST_H

typedef struct Board Board;

Board * new_Board(int width, int height);

void delete_Board(Board ** toDelete);

#endif
