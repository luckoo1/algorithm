#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
vector<vector<int>> MAP(22, vector<int>(22, 0));
vector<vector<bool>> g_check(22, vector<bool>(22, false));
vector<int> dice{2, 1, 5, 6, 4, 3};

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

void PRINT_VEC(vector<vector<int>> vec)
{
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

struct DATA
{
    int r;
    int c;
    DATA(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

vector<int> rotate_left()
{
    vector<int> temp = dice;
    temp[1] = dice[5];
    temp[3] = dice[4];
    temp[4] = dice[1];
    temp[5] = dice[3];
    return temp;
}
vector<int> rotate_right()
{
    vector<int> temp = dice;
    temp[1] = dice[4];
    temp[3] = dice[5];
    temp[4] = dice[3];
    temp[5] = dice[1];
    return temp;
}
vector<int> rotate_up()
{
    vector<int> temp = dice;
    temp[0] = dice[1];
    temp[1] = dice[2];
    temp[2] = dice[3];
    temp[3] = dice[0];
    return temp;
}
vector<int> rotate_down()
{
    vector<int> temp = dice;
    temp[0] = dice[3];
    temp[1] = dice[0];
    temp[2] = dice[1];
    temp[3] = dice[2];
    return temp;
}

void bfs(int r, int c)
{
    vector<vector<bool>> visited(22, vector<bool>(22, false));

    queue<DATA> q;
    q.push(DATA(r, c));
    g_check[r][c] = true;
    visited[r][c] = true;

    int number = MAP[r][c];
    int cnt = 1;

    while (!q.empty())
    {
        int start_R = q.front().r;
        int start_C = q.front().c;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_R = start_R + DR[k];
            int move_C = start_C + DC[k];

            if (move_R < 1 || move_C < 1 || move_R > N || move_C > M)
                continue;
            if (g_check[move_R][move_C] == true)
                continue;
            if (MAP[move_R][move_C] != number)
                continue;

            q.push(DATA(move_R, move_C));
            g_check[move_R][move_C] = true;
            visited[move_R][move_C] = true;
            cnt += 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (visited[i][j] == true)
            {
                MAP[i][j] = MAP[i][j] * cnt;
            }
        }
    }
}
int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (g_check[i][j] == false)
            {
                bfs(i, j);
            }
        }
    }
    
}