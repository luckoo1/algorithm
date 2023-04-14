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

int DR[4]={1,-1,0,0};
int DC[4]={0,0,1,-1};

int main()
{
    freopen("Input.txt", "r", stdin);
    cin >> N >> M;

    vector<vector<int>> MAP(N, vector<int>(M, 0));
    vector<vector<bool>> check(N, vector<bool>(M, false));
    queue<DATA> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
            {
                q.push(DATA(i, j));
                check[i][j] = true;
            }
        }
    }

    while(!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;

    }    


}

/*
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/