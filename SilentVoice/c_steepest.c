#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Node {
    int hval;
    int board[SIZE][SIZE];
} Node;

void Hfun(Node *node, Node *goal) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (node->board[i][j] != goal->board[i][j]) {
                count++;
            }
        }
    }
    node->hval = count;
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

typedef struct Position {
    int x;
    int y;
} Position;

void zeroposition(Node *node, Position *pos) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (node->board[i][j] == 0) {
                pos->x = i;
                pos->y = j;
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
    Node initial = {.board = {{0, 1, 4}, {3, 2, 5}, {7, 6, 8}}};
    Hfun(&initial, &goal);

    int minimum = 10;
    Position curr;
    Node tempBoard;
    PrintBoard(&initial);
    printf("Heuristic value = %d\n\n", initial.hval);
    printf("***********************************************\n");

    while (initial.hval < minimum && initial.hval != 0) {
        minimum = initial.hval;
        tempBoard = initial;
        zeroposition(&tempBoard, &curr);

        if (curr.x + 1 < SIZE) {
            swap(&tempBoard.board[curr.x + 1][curr.y], &tempBoard.board[curr.x][curr.y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
            }
            swap(&tempBoard.board[curr.x + 1][curr.y], &tempBoard.board[curr.x][curr.y]);
        }
        if (curr.y + 1 < SIZE) {
            swap(&tempBoard.board[curr.x][curr.y + 1], &tempBoard.board[curr.x][curr.y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
            }
            swap(&tempBoard.board[curr.x][curr.y + 1], &tempBoard.board[curr.x][curr.y]);
        }
        if (curr.x - 1 >= 0) {
            swap(&tempBoard.board[curr.x - 1][curr.y], &tempBoard.board[curr.x][curr.y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
            }
            swap(&tempBoard.board[curr.x - 1][curr.y], &tempBoard.board[curr.x][curr.y]);
        }
        if (curr.y - 1 >= 0) {
            swap(&tempBoard.board[curr.x][curr.y - 1], &tempBoard.board[curr.x][curr.y]);
            Hfun(&tempBoard, &goal);
            if (tempBoard.hval < initial.hval) {
                initial = tempBoard;
            }
            swap(&tempBoard.board[curr.x][curr.y - 1], &tempBoard.board[curr.x][curr.y]);
        }
        PrintBoard(&initial);
        printf("Heuristic value = %d\n\n", initial.hval);
        printf("***********************************************\n");
    }

    return 0;
}
