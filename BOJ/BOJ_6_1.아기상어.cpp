#include <iostream>
#include <queue>
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

int N;
vector<vector<int>> MAP(21, vector<int>(21, 0));
vector<vector<int>> dist(21, vector<int>(21, 0));
int shark_row, shark_col, shark_size;
int flag = 0;
int eat_fish = 0;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void bfs(int start_row, int start_col, int shark_size)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = 0;
        }
    }

    vector<vector<bool>> check(21, vector<bool>(21, false));
    queue<DATA> q;
    q.push(DATA(start_row, start_col));

    while (!q.empty())
    {
        int now_row = q.front().row;
        int now_col = q.front().col;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_row = now_row + dr[k];
            int move_col = now_col + dc[k];
            if (move_row < 0 || move_col < 0 || move_row >= N || move_col >= N)
            {
                continue;
            }
            if (check[move_row][move_col] == true)
            {
                continue;
            }
            if (MAP[move_row][move_col] > shark_size)
            {
                continue;
            }
            if (MAP[move_row][move_col] <= shark_size)
            {
                q.push(DATA(move_row, move_col));
                check[move_row][move_col] = true;
                dist[move_row][move_col] = dist[now_row][now_col] + 1;

                if (MAP[move_row][move_col] < shark_size && MAP[move_row][move_col] != 0)
                {
                    flag = 1;
                }
            }
        }
    }

    return;
}

int main()
{
    cin >> N;
    int shark_size = 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 9)
            {
                shark_row = i;
                shark_col = j;
            }
        }
    }
    MAP[shark_row][shark_col] = 0;
    int answer = 0;

    while (1)
    {
        int min_dist = 99999999;
        vector<vector<bool>> shark(21, vector<bool>(21, false));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAP[i][j] != 0)
                {
                    shark[i][j] = true;
                }
            }
        }

        flag = 0;

        bfs(shark_row, shark_col, shark_size);

        if (flag == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][j] != 0 && shark[i][j] == true && MAP[i][j] < shark_size)
                {
                    int temp_dist = dist[i][j];
                    if (temp_dist < min_dist)
                    {
                        min_dist = temp_dist;
                    }
                }
            }
        }

        int flag2 = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dist[i][j] == min_dist && shark[i][j] == true && MAP[i][j] < shark_size)
                {
                    MAP[i][j] = 0;
                    eat_fish++;
                    answer += dist[i][j];
                    shark_row = i;
                    shark_col = j;
                    flag2 = 1;
                    break;
                }
            }
            if (flag2 == 1)
            {
                break;
            }
        }
        if (shark_size == eat_fish)
        {
            shark_size++;
            eat_fish = 0;
        }

#if 0
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout<<MAP[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

#endif
    }

    cout << answer;
}