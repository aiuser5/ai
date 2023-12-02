#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct {
    int cost;
    int hval;
    int board[SIZE][SIZE];
} Node;

void Hfun(Node *current, Node *goal) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (current->board[i][j] != goal->board[i][j]) {
                count++;
            }
        }
    }
    current->hval = count;
}

void PrintBoard(Node *node) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", node->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void zeroposition(Node *node, int *x, int *y) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (node->board[i][j] == 0) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    Node goal = {.board = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}};
    Node initial = {.board = {{4, 1, 3}, {7, 2, 6}, {0, 5, 8}}};
    Hfun(&initial, &goal);

    int minimum = 10;
    int curr_x, curr_y;
    Node tempBoard;

    while (initial.hval < minimum && initial.hval != 0) {
        PrintBoard(&initial);
        printf("Heuristic value = %d\n\n", initial.hval);
        printf("***********************************************\n");
        minimum = initial.hval;
        tempBoard = initial;
        zeroposition(&tempBoard, &curr_x, &curr_y);

        if (curr_x + 1 < SIZE) {
            swap(&tempBoard.board[curr_x + 1][curr_y], &tempBoard.board[curr_x][curr_y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
                continue;
            }
            swap(&tempBoard.board[curr_x + 1][curr_y], &tempBoard.board[curr_x][curr_y]);
        }
        if (curr_y + 1 < SIZE) {
            swap(&tempBoard.board[curr_x][curr_y + 1], &tempBoard.board[curr_x][curr_y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
                continue;
            }
            swap(&tempBoard.board[curr_x][curr_y + 1], &tempBoard.board[curr_x][curr_y]);
        }
        if (curr_x - 1 >= 0) {
            swap(&tempBoard.board[curr_x - 1][curr_y], &tempBoard.board[curr_x][curr_y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
                continue;
            }
            swap(&tempBoard.board[curr_x - 1][curr_y], &tempBoard.board[curr_x][curr_y]);
        }
        if (curr_y - 1 >= 0) {
            swap(&tempBoard.board[curr_x][curr_y - 1], &tempBoard.board[curr_x][curr_y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
                continue;
            }
            swap(&tempBoard.board[curr_x][curr_y - 1], &tempBoard.board[curr_x][curr_y]);
        }
    }

    PrintBoard(&initial);
    printf("Heuristic value = %d\n\n", initial.hval);

    return 0;
}

