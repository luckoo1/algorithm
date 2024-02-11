#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c;
int ans = 0;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int check[200] = {false};

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
vector<DATA> zero_map;
vector<DATA> virus_map;
vector<vector<int>> map(9, vector<int>(9, 0));
queue<DATA> q;

void cnt_ans(vector<vector<int>> tmp_map)
{
    int tmp_ans = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (tmp_map[i][j] == 0)
            {
                tmp_ans += 1;
            }
        }
    }
    if (tmp_ans > ans)
        ans = tmp_ans;
}

void spread(vector<vector<int>> tmp_map)
{
    for (int i = 0; i < virus_map.size(); i++)
    {
        q.push(DATA(virus_map[i].r, virus_map[i].c));
    }

    while (!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_r = now_r + dr[k];
            int move_c = now_c + dc[k];
            if (move_r < 0 || move_c < 0 || move_r >= r || move_c >= c)
                continue;
            if (tmp_map[move_r][move_c] == 2 || tmp_map[move_r][move_c] == 1)
                continue;
            tmp_map[move_r][move_c]=2;
            q.push(DATA(move_r,move_c));
        }
    }
    cnt_ans(tmp_map);
}

void dfs(int dep, int k)
{
    if (dep == 3)
    {
        spread(map);
        return;
    }
    for (int i = k; i < zero_map.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            map[zero_map[i].r][zero_map[i].c] = 2;
            dfs(dep + 1, k + 1);
            check[i] = false;
            map[zero_map[i].r][zero_map[i].c] = 0;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> r >> c;
    int temp_num;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> temp_num;
            map[i][j] = temp_num;
            if (temp_num == 0)
            {
                zero_map.push_back(DATA(i, j));
            }
            if (temp_num == 2)
            {
                virus_map.push_back(DATA(i, j));
            }
        }
    }
    dfs(0, 0);
    cout<<ans;
}

#if 0
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<temp_map[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
#endif