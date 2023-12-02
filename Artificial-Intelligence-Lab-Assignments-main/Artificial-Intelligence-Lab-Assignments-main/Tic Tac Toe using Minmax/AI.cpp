#include <bits/stdc++.h>
using namespace std;

int nxtmove;

int checkBoardPostion(vector<int> &Board)
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
        if (count[0] < count[1])
        {
            nxtmove = 1;
        }
        else if (count[0] > count[1])
        {
            nxtmove = 2;
        }
        else
        {
            nxtmove = 1;
        }
    }
    else
    {
        cout << "NOT Valid Board Position"
             << "\n";
    }
}

void PrintBoard(vector<int> &Temp)
{
    int j;
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "\n";
        }
        cout << Temp[i] << " ";
    }
    cout << "\n";
}

vector<vector<int>> PossibleMoveGenerator(vector<int> &Board)
{
    vector<vector<int>> MoveMatrix;
    for (int i = 0; i < 9; i++)
    {
        if (Board[i] == 0)
        {
            vector<int> Temp = Board;
            Temp[i] = nxtmove;
            PrintBoard(Temp);
            MoveMatrix.push_back(Temp);
        }
    }
    return MoveMatrix;
}

bool WinEvaluator(vector<int> &Board)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (Board[i] != 0 && Board[i] == Board[i + 1] && Board[i] == Board[i + 2])
        {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (Board[i] != 0 && Board[i] == Board[i + 3] && Board[i] == Board[i + 6])
        {
            return 1;
        }
    }
    if (Board[0] != 0 && Board[0] == Board[4] && Board[0] == Board[8])
    {
        return 1;
    }
    else if (Board[2] != 0 && Board[2] == Board[4] && Board[2] == Board[6])
    {
        return 1;
    }
    else
    {
        cout << "NO Win" << endl;
        return 0;
    }
}

bool Blocker(vector<int> &Board)
{
    bool flag;
    int count = 0;
    vector<vector<int>> MoveMatrix;
    nxtmove = 3 - nxtmove;
    MoveMatrix = PossibleMoveGenerator(Board);
    for (auto i : MoveMatrix)
    {
        flag = WinEvaluator(i);
        if (flag)
        {
            
            return 1;
        }
    }
}

int main()
{
    int score = 0;
    int flag = 0;
    int pos;
    vector<int> Board(9, 0);
    int nxtmove;
    vector<vector<int>> MoveMatrix;

    while (true)
    {
        PrintBoard(Board);
        checkBoardPostion(Board);
        if (nxtmove == 2)
        {
            cout << "Enter Move Postion : ";
            cin >> pos;
        }
        MoveMatrix = PossibleMoveGenerator(Board);
        for (auto i : MoveMatrix)
        {
            flag = WinEvaluator(i);
            if (flag)
            {
                score += 60;
                cout << "Player " << nxtmove << "won the Game";
                PrintBoard(i);
                break;
            }
        }
        if (!flag)
        {
            flag = Blocker(Board);
            if (flag)
            {
                score+=50;
            }
            
            score += 50;
        }
    }
    return 0;
}
