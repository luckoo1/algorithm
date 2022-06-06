#include <iostream>
#include <vector>
using namespace std;

struct DATA
{
    int row;
    int col;
    int type;
    DATA(int row, int col, int type)
    {
        this->row = row;
        this->col = col;
        this->type = type;
    }
};

int ROW, COL;

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

//위 오른 아래 왼
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int answer = 9999999;

vector<vector<int>> map(10, vector<int>(10, 0));
vector<vector<bool>> check(10, vector<bool>(10, false));
vector<DATA> camera;

void camera_on(int row, int col, int where)
{
    while (1)
    {
        row = row + dr[where];
        col = col + dc[where];
        if (row < 0 || row >= ROW || col < 0 || col >= COL)
        {
            break;
        }
        if (check[row][col] == true)
        {
            break;
        }
        map[row][col]++;
    }
}

void camera_off(int row, int col, int where)
{
    while (1)
    {
        row = row + dr[where];
        col = col + dc[where];
        if (row < 0 || row >= ROW || col < 0 || col >= COL)
        {
            break;
        }
        if (check[row][col] == true)
        {
            break;
        }
        map[row][col]--;
    }
}

void dfs(int dep)
{
    if (dep == camera.size())
    {
        int cnt =0;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if(map[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        if(cnt<answer)
        {
            answer=cnt;
        }
        return;
    }

    int now_row = camera[dep].row;
    int now_col = camera[dep].col;
    int type = camera[dep].type;

    if (type == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            camera_on(now_row, now_col, i);
            dfs(dep + 1);
            camera_off(now_row, now_col, i);
        }
    }
    if (type == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            camera_on(now_row, now_col, i);
            camera_on(now_row, now_col, (i + 2)%4);
            dfs(dep + 1);
            camera_off(now_row, now_col, i);
            camera_off(now_row, now_col, (i + 2)%4);
        }
    }
    if (type == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            camera_on(now_row, now_col, i);
            camera_on(now_row, now_col, (i + 1) % 4);
            dfs(dep + 1);
            camera_off(now_row, now_col, i);
            camera_off(now_row, now_col, (i + 1) % 4);
        }
    }
    if (type == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            camera_on(now_row, now_col, i);
            camera_on(now_row, now_col, (i + 1) % 4);
            camera_on(now_row, now_col, (i + 2) % 4);
            dfs(dep + 1);
            camera_off(now_row, now_col, i);
            camera_off(now_row, now_col, (i + 1) % 4);
            camera_off(now_row, now_col, (i + 2) % 4);
        }
    }
    if (type == 5)
    {
        camera_on(now_row, now_col, 0);
        camera_on(now_row, now_col, 1);
        camera_on(now_row, now_col, 2);
        camera_on(now_row, now_col, 3);
        dfs(dep + 1);
        camera_off(now_row, now_col, 0);
        camera_off(now_row, now_col, 1);
        camera_off(now_row, now_col, 2);
        camera_off(now_row, now_col, 3);
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
            if (map[i][j] != 0 && map[i][j] != 6)
            {
                camera.push_back(DATA(i, j, map[i][j]));
            }
            if (map[i][j] != 0)
            {
                check[i][j] = true;
            }
        }
    }
    dfs(0);

    printf("%d", answer);
}