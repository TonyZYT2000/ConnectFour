#include <stdio.h>
#include "board.h"
#include "player.h"

int main(void) {
    Board * thisBoard = new_Board(7, 6);
    Player * human1 = new_Player(1, 'x', thisBoard, human_Move);
    Player * human2 = new_Player(2, 'o', thisBoard, human_Move);
    Player * computer = new_Player(3, 'c', thisBoard, rand_Move);
    Player * playerArr[] = {human1, human2, computer};
    print_Board(thisBoard);

    int index = 0;
    int col = human1->move(human1);
    checkwin(thisBoard, col);
    print_Board(thisBoard);
    while(!thisBoard->win && !thisBoard->full) {
        index += 1;
        index %= 3;
        col = playerArr[index]->move(playerArr[index]);
        checkwin(thisBoard, col);
        checkfull(thisBoard);
        print_Board(thisBoard);
    }

    if (thisBoard->win) {
        printf("Player %c win!\n", playerArr[index]->chess);
    } else {
        printf("Board is full. Tie!\n");
    }

    delete_Player(&human1);
    delete_Player(&human2);
    delete_Player(&computer);
    delete_Board(&thisBoard);
    return 0;
}
