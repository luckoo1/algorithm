/*
동시사건을 잘알자
1.미세먼지가 확산된다. ★확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 Ar,c/5이고 소수점은 버린다.
(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.


2. 공기청정기가 작동한다.
공기청정기에서는 바람이 나온다.
위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

이 조건대로 구현했다.
*/
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
    for (int MANY = 0; MANY < HOW_MANY; MANY++)
    {
        dist.clear();
        vector<vector<int>> temp_map(51, vector<int>(51, 0));

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
                temp_map[move_row][move_col] += map[now_row][now_col] / 5;
                cnt++;
            }

            map[now_row][now_col] = map[now_row][now_col] - (map[now_row][now_col] / 5 * cnt);
        }

        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (map[i][j] >= 0)
                {
                    map[i][j]+=temp_map[i][j];
                }
            }
        }
        rotate_ban_time(refresh[0].row, refresh[0].col);
        rotate_time(refresh[1].row, refresh[1].col);
    }

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

    cout << answer;
}