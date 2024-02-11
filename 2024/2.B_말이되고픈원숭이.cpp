#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PRINT (0)

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int hr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int map[200][200];
int dist[30][200][200];
int flag = 0;
int ans = -1;
int r, c, d;
struct DATA
{
    int d, r, c;
    DATA(int d, int r, int c)
    {
        this->d = d;
        this->r = r;
        this->c = c;
    }
};

bool no_range(int mr, int mc)
{
    if (mr < 0 || mr >= r || mc < 0 || mc >= c)
        return true;
    else
        return false;
}
bool alreay_visit(int d, int r, int c)
{
    if (dist[d][r][c] != 0)
        return true;
    else
        return false;
}
bool is_wall(int r, int c)
{
    if (map[r][c] == 1)
        return true;
    else
        return false;
}
void bfs()
{
    queue<DATA> q;
    q.push(DATA(0, 0, 0));

    while (!q.empty())
    {
        int nd = q.front().d;
        int nr = q.front().r;
        int nc = q.front().c;
        if(nr == r-1 && nc == c-1)
        {
            flag = 1;
            ans = dist[nd][nr][nc];
            break;
        }
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int mr = nr + dr[k];
            int mc = nc + dc[k];
            if (no_range(mr, mc))
                continue;
            if (alreay_visit(nd, mr, mc))
                continue;
            if (is_wall(mr, mc))
                continue;
            q.push(DATA(nd, mr, mc));
            dist[nd][mr][mc] = dist[nd][nr][nc] + 1;
        }
        if (nd < d)
        {
            for (int k = 0; k < 8; k++)
            {
                int mr = nr + hr[k];
                int mc = nc + hc[k];
                if (no_range(mr, mc))
                    continue;
                if (alreay_visit(nd + 1, mr, mc))
                    continue;
                if (is_wall(mr, mc))
                    continue;
                q.push(DATA(nd + 1, mr, mc));
                dist[nd + 1][mr][mc] = dist[nd][nr][nc] + 1;
            }
        }
    }
}

int main()
{
#if (PRINT == 1)
    freopen("input.txt", "r", stdin);
#endif
    cin >> d;
    cin >> c >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    bfs();
    #if (PRINT == 1)
    for(int k=0;k<=d;k++){
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout<<dist[k][i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    #endif
    cout<<ans;
}