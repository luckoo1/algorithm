//효율성에서 틀림
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ROW;
int COL;

bool check(vector<vector<int>> board, int row, int col, int n)
{
    if (row + n > ROW || col + n > COL)
        return false;

    for (int i = row; i < row + n; i++)
        for (int j = col; j < col + n; j++)
        {
            if (board[i][j] == 0)
                return false;
        }

    return true;
}

int solution(vector<vector<int>> board)
{
    ROW = board.size();
    COL = board[0].size();
    int n = 1;

    for (int i = 0; i <= ROW - n; i++)
    {
        for (int j = 0; j <= COL - n; j++)
        {
            while (1)
            {
                bool flag = false;
                if (check(board, i, j, n) == true)
                {
                    flag = true;
                    n = n + 1;
                }
                if (flag == false)
                    break;
            }
        }
    }
    return (n - 1) * (n - 1);
}

int main()
{
    vector<vector<int>> a{{0, 1, 1, 1},
                          {1, 1, 1, 1},
                          {1, 1, 1, 1},
                          {0, 0, 1, 0}};
    cout << "ANSWER : " << solution(a) << endl;

    vector<vector<int>> b{{0, 0, 1, 1},
                          {1, 1, 1, 1}};
    cout << "ANSWER : " << solution(b) << endl;

    vector<vector<int>> c{{0, 0, 0, 1},
                          {1, 1, 1, 1},
                          {1, 1, 1, 1},
                          {0, 0, 1, 0}};
    cout << "ANSWER : " << solution(c) << endl;
}