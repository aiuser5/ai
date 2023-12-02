#include <bits/stdc++.h>
using namespace std;

void Index(vector<int> &Board)
{
    int index = 0;
    int size = 9;
    for (int i = 0; i < size; i++)
    {
        index += Board[i] * pow(3, size - i - 1);
    }
    cout << "INDEX of Current Board Position = " << index << "\n";
}

void checkBoardPostion(vector<int> &Board)
{
    int count[] = {0, 0};
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
        cout << "Valid Board Position"
             << "\n";
    }
    else
    {
        cout << "NOT Valid Board Position"
             << "\n";
    }
}
void PrintBoard(vector<int> &Board)
{
    int j;
    for (int i = 0; i < 9; i++)
    {
        if (i%3==0)
        {
            cout << "\n";
        }
        cout << Board[i] << " ";
    }
    cout << "\n";
}
int main()
{

    vector<int> Board = {2, 2, 1, 1, 0, 0, 0, 1, 0};

    PrintBoard(Board);
    checkBoardPostion(Board);
    Index(Board);
    cout << flush;

    return 0;
}
