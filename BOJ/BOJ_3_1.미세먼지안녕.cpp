#include <iostream>
#include <vector>
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

//위 오른 아래 왼
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int ROW, COL, HOW_MANY;
vector<vector<int>> map(51, vector<int>(51, 0));
vector<vector<int>> temp_map(51, vector<int>(51, 0));
vector<DATA> refresh;

void print(vector<vector<int>> &map)
{
    cout << endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate_ban_time(int row, int col)
{
    for (int i = row - 1; i >= 1; i--)
    {
        map[i][0] = map[i - 1][0];
    }
    for (int i = 0; i <= COL - 2; i++)
    {
        map[0][i] = map[0][i + 1];
    }
    for (int i = 0; i <= row - 1; i++)
    {
        map[i][COL - 1] = map[i + 1][COL - 1];
    }
    for (int i = COL - 1; i >= 1; i--)
    {
        map[row][i] = map[row][i - 1];
    }

    map[row][col + 1] = 0;
}

void rotate_time(int row, int col)
{
    for (int i = row + 1; i <= ROW - 2; i++)
    {
        map[i][0] = map[i + 1][0];
    }
    for (int i = 0; i <= COL - 2; i++)
    {
        map[ROW - 1][i] = map[ROW - 1][i + 1];
    }
    for (int i = ROW - 1; i >= row + 1; i--)
    {
        map[i][COL - 1] = map[i - 1][COL - 1];
    }
    for (int i = COL - 1; i >= 1; i--)
    {
        map[row][i] = map[row][i - 1];
    }
    map[row][col + 1] = 0;
}

int main()
{
    cin >> ROW >> COL >> HOW_MANY;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1)
            {
                refresh.push_back(DATA(i, j));
            }
        }
    }

    vector<DATA> dist;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] > 0)
            {
                dist.push_back(DATA(i, j));
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        int cnt = 0;
        int now_row = dist[i].row;
        int now_col = dist[i].col;
        for (int k = 0; k < 4; k++)
        {
            int move_row = now_row + dr[k];
            int move_col = now_col + dc[k];
            if (move_row < 0 || move_col < 0 || move_row >= ROW || move_col >= COL)
            {
                continue;
            }
            if (map[move_row][move_col] == -1)
            {
                continue;
            }
            map[move_row][move_col] += map[now_col][now_col] / 5;
            cnt++;
        }
        map[now_row][now_col] = map[now_row][now_row] / 5;
    }

    map = temp_map;

    print(map);

    rotate_ban_time(refresh[0].row, refresh[0].col);
    rotate_time(refresh[1].row, refresh[1].col);
    map[refresh[0].row][refresh[0].col] = -1;
    map[refresh[1].row][refresh[1].col] = -1;

    print(map);

    int answer = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] > 0)
            {
                answer += map[i][j];
            }
        }
    }
    cout << answer + 2;
}