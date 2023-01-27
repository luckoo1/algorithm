#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool check[101][101];

struct Data
{
    int row;
    int col;
    Data(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int max_row = board.size();
    int max_col = board[0].size();

    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_col; j++)
        {
            if (board[i][j] == 1)
            {
                check[i][j] = true;
            }
        }
    }

    queue<Data> q;
    check[0][0] = true;
    q.push(Data(0, 0));
    while (!q.empty())
    {
        int row = q.front().row;
        int col = q.front().col;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int new_row = row + dr[k];
            int new_col = col + dc[k];
            if (check[new_row][new_col] == true)
            {
                continue;
            }
            if (new_row < 0 || new_row >= max_row || new_col < 0 || new_col >= max_col)
            {
                continue;
            }
            check[new_row][new_col] = true;
            q.push(Data(new_row, new_col));
            board[new_row][new_col] = board[row][col] + 1;
        }
    }

    return answer;
}
int main()
{
    cout << solution(
        {{0, 0, 0, 1, 1},
         {0, 0, 0, 1, 0},
         {0, 1, 0, 1, 1},
         {1, 1, 0, 0, 1},
         {0, 0, 0, 0, 0}});
}