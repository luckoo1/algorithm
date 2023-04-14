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

vector<vector<bool>> check(10, vector<bool>(10, false));
vector<bool> wall_check(999,false);
queue<DATA> q;

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int ans = 999;

void spread()
{
}

void dfs(int dep, int k,vector<vector<int>> &MAP,vector<DATA> &zero)
{
    if (dep == 3)
    {
        spread();
        return;
    }
    for(int i=k;i<zero.size();i++)
    {
        if(wall_check[i]==false)
        {
            wall_check[i]=true;
            MAP[zero[i].r][zero[i].c]=1;
            dfs(dep+1,k+1,MAP,zero);
            wall_check[i]=false;
            MAP[zero[i].r][zero[i].c]=0;
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
            {
                q.push(DATA(i, j));
                check[i][j] = true;
                zero.push_back(DATA(i,j));
            }
        }
    }

    dfs(0, 0,MAP,zero);
}