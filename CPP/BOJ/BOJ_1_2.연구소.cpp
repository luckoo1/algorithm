#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int ROW, COL;
int map[9][9];
int num[3];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int ans;

struct DATA
{
    int r = r;
    int c = c;
    DATA(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

vector<DATA> zero;
queue<DATA> q;

void bfs()
{
    int temp = 0;
    bool check[9][9] = {false};
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 2)
            {
                q.push(DATA(i, j));
                check[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL)
                continue;
            if (map[nr][nc] == 0 && check[nr][nc] == false)
            {
                check[nr][nc] = true;
                q.push(DATA(nr, nc));
            }
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 0 && check[i][j] == false)
            {
                temp += 1;
            }
        }
    }

    if (temp > ans)
    {
        ans = temp;
    }
}

void dfs(int dep, int x)
{
    if (dep == 3)
    {
        map[zero[num[0]].r][zero[num[0]].c] = 1;
        map[zero[num[1]].r][zero[num[1]].c] = 1;
        map[zero[num[2]].r][zero[num[2]].c] = 1;
        bfs();
        map[zero[num[0]].r][zero[num[0]].c] = 0;
        map[zero[num[1]].r][zero[num[1]].c] = 0;
        map[zero[num[2]].r][zero[num[2]].c] = 0;
        return;
    }

    for (int i = x; i < zero.size(); i++)
    {
        num[dep] = i;
        dfs(dep + 1, i + 1);
    }
}

int main()
{
    scanf("%d %d", &ROW, &COL);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
            {
                zero.push_back(DATA(i, j));
            }
        }
    }
    dfs(0, 0);

    printf("%d", ans);
}