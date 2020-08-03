#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "player.h"

int main(void) {
    int width = 0;
    int height = 0;
    int humanNum = 0;
    int computerNum = 0;

    printf("Welcome to ZYT's Connect Four game!\n");
    printf("Regular Connect Four game is a two-player game, and the board size if 6 rows * 7 columns.\n");
    printf("But, in ZYT's Connect Four game, you can customize player number and board size!\n");
    printf("Please enter human player number: ");
    scanf("%d", &humanNum);
    printf("Please enter computer player number: ");
    scanf("%d", &computerNum);
    printf("Now, please enter board width: ");
    scanf("%d", &width);
    printf("Now, please enter board height: ");
    scanf("%d", &height);

    Board * board = new_Board(width, height);
    Player ** playerArr = malloc((humanNum + computerNum) * sizeof(Player *));

    for (int i = 0; i < humanNum + computerNum; i++) {
        char chess;
        if (i < humanNum) {
            printf("Hi human player %d! Please enter a chess you want to use: ", i + 1);
            fflush(stdin);
            scanf("%c", &chess);
            playerArr[i] = new_Player(i + 1, chess, board, human_Move);
        } else {
            printf("Please enter a chess for computer player %d: ", i - humanNum + 1);
            fflush(stdin);
            scanf("%c", &chess);
            playerArr[i] = new_Player(i - humanNum + 1,chess, board, rand_Move);
        }
    }

    int index = -1;
    print_Board(board);
    while (!board->win && !board->full) {
        index += 1;
        index %= humanNum + computerNum;
        int col = playerArr[index]->move(playerArr[index]);
        checkwin(board, col);
        checkfull(board);
        print_Board(board);
    }

    if (board->win) {
        if (index < humanNum) {
            printf("Human player %d win! Congratulation!", index + 1);
        } else {
            printf("Computer player %d win! AI uprising!", index - humanNum + 1);
        }
    } else {
        printf("Board is full. Tie!\n");
    }

    for (int i = 0; i < humanNum + computerNum; i++) {
        delete_Player(&playerArr[i]);
    }
    free(playerArr);
    delete_Board(&board);
}

