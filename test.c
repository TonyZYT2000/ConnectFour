#include <stdio.h>
#include "board.h"

int main(void) {
    Board * thisBoard = new_Board(7, 4);
    print_Board(thisBoard);

    int input = 0;
    printf("Plese enter a col number: ");
    scanf("%d", &input);
    while (input >= 1 && input <= 7) {
        bool success = put(thisBoard, input, 'x');
        if (!success) {
            printf("That col is full!\n");
            printf("Plese reenter a col number: ");
            scanf("%d", &input);
            continue;
        }
        print_Board(thisBoard);
        printf("Plese input a col number: ");
        scanf("%d", &input);
    }

    delete_Board(&thisBoard);
    return 0;
}
