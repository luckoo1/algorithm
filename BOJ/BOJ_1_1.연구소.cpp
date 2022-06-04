#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DATA
{
    int row;
    int col;
    DATA(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

queue<DATA> q;
vector<DATA> wall;
int ROW, COL;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
vector<vector<int>> map(9, vector<int>(9, 0));
vector<vector<int>> reset_map(9, vector<int>(9, 0));
vector<vector<bool>> visited;

vector<bool> check(99999, false);
int answer = 0;


void bfs(vector<vector<int>> &map)
{
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 2)
            {
                q.push(DATA(i, j));
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {

        int now_row = q.front().row;
        int now_col = q.front().col;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_row = now_row + dr[k];
            int move_col = now_col + dc[k];
            if (move_row < 0 || move_col < 0 || move_row >= ROW || move_col >= COL)
            {
                continue;
            }
            if (visited[move_row][move_col] == true ||map[move_row][move_col] == 1)
            {
                continue;
            }
            q.push(DATA(move_row, move_col));
            visited[move_row][move_col] = true;
            map[move_row][move_col] = 2;
        }
    }
    int cnt = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 0)
            {
                cnt++;
            }
        }
    }


    if (cnt > answer)
    {
        answer = cnt;
    }
}

void dfs(int dep, int k)
{
    if (dep == 3)
    {
        reset_map = map;
        bfs(map);
        map = reset_map;

        return;
    }

    for (int i = k; i < wall.size(); i++)
    {
        if (check[i] == false)
        {
            map[wall[i].row][wall[i].col] = 1;
            check[i] = true;
            dfs(dep + 1, i + 1);
            map[wall[i].row][wall[i].col] = 0;
            check[i] = false;
        }
    }
}

int main()
{
    cin >> ROW >> COL;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 0)
            {
                wall.push_back(DATA(i, j));
            }
        }
    }

    dfs(0, 0);

    cout << answer;
}