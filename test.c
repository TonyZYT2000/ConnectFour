#include <stdio.h>
#include "board.h"

int main(void) {
    Board * thisBoard = new_Board(7, 4);
    print_Board(thisBoard);
    delete_Board(&thisBoard);
    return 0;
}
