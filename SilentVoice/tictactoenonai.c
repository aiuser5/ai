#include <stdio.h>
#include <math.h>

void Index(int Board[])
{
    int index = 0;
    int size = 9;
    for (int i = 0; i < size; i++)
    {
        index += Board[i] * (int)pow(3, size - i - 1);
    }
    printf("INDEX of Current Board Position = %d\n", index);
}

void checkBoardPosition(int Board[])
{
    int count[2] = {0, 0};
    for (int i = 0; i < 9; i++)
    {
        if (Board[i] == 1)
        {
            count[0] += 1;
        }
        else if (Board[i] == 2)
        {
            count[1] += 1;
        }
    }
    if (abs(count[0] - count[1]) <= 1)
    {
        printf("Valid Board Position\n");
    }
    else
    {
        printf("NOT Valid Board Position\n");
    }
}

void PrintBoard(int Board[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            printf("\n");
        }
        printf("%d ", Board[i]);
    }
    printf("\n");
}

int main()
{
    int Board[9] = {2, 2, 1, 1, 0, 0, 0, 1, 0};

    PrintBoard(Board);
    checkBoardPosition(Board);
    Index(Board);
    // fflush(stdout);

    return 0;
}