#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

int N, M;
vector<bool> wall_check(999, false);
vector<DATA> virus;

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int ans = 0;

void spread(vector<vector<int>> MAP)
{
    queue<DATA> q;
    vector<vector<bool>> check(10, vector<bool>(10, false));
    for (int i = 0; i < virus.size(); i++)
        q.push(DATA(virus[i].r, virus[i].c));

    while (!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_r = now_r + DR[k];
            int move_c = now_c + DC[k];
            if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= M)
                continue;
            if (MAP[move_r][move_c] == 1 || MAP[move_r][move_c] == 2)
                continue;

            MAP[move_r][move_c] = 2;
            q.push(DATA(move_r, move_c));
        }
    }
    int temp_ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(MAP[i][j]==0)
                temp_ans+=1;
        }
    }
    if(ans<temp_ans)
        ans = temp_ans;
    return;
}

void dfs(int dep, int k, vector<vector<int>> &MAP, vector<DATA> zero)
{
    if (dep == 3)
    {
        spread(MAP);
        return;
    }
    for (int i = k; i < zero.size(); i++)
    {
        if (wall_check[i] == false)
        {
            wall_check[i] = true;
            MAP[zero[i].r][zero[i].c] = 1;
            dfs(dep + 1, i + 1, MAP, zero);
            wall_check[i] = false;
            MAP[zero[i].r][zero[i].c] = 0;
        }
    }
}

int main()
{
    freopen("Input.txt", "r", stdin);
    cin >> N >> M;

    vector<vector<int>> MAP(N, vector<int>(M, 0));
    vector<DATA> zero;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
                virus.push_back(DATA(i, j));
            if (MAP[i][j] == 0)
                zero.push_back(DATA(i, j));
        }
    }

    dfs(0, 0, MAP, zero);
    cout<<ans;
}

// for(int i=0;i<N;i++)
// {
//     for(int j=0;j<M;j++)
//     {
//         cout<<MAP[i][j]<<" ";
//     }
//     cout<<endl;
// }
// cout<<endl;