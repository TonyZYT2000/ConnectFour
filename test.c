#include <stdio.h>
#include "board.h"

int main(void) {
    Board * thisBoard = new_Board(7, 6);
    print_Board(thisBoard);

    int input = 0;
    char chess = '.';
    printf("Please enter a col number and a chess: ");
    scanf("%d,%c", &input, &chess);
    while (input >= 1 && input <= 7) {
        bool success = put(thisBoard, input, chess);
        if (!success) {
            printf("That col is full!\n");
            printf("Plese reenter a col number: ");
            scanf("%d", &input);
            continue;
        }
        checkwin(thisBoard, input);
        print_Board(thisBoard);
        if (thisBoard->win) {
            printf("You win!\n");
            break;
        }
        printf("Please enter a col number and a chess: ");
        scanf("%d,%c", &input, &chess);
    }

    delete_Board(&thisBoard);
    return 0;
}
