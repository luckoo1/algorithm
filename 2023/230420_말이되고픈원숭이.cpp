#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int HR[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int HC[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool check[201][201][31] = {false};
int dist[201][201][31] = {0};

struct DATA
{
    int r;
    int c;
    int k;
    DATA(int r, int c, int k)
    {
        this->r = r;
        this->c = c;
        this->k = k;
    }
};

int main()
{
    //freopen("Input.txt", "r", stdin);
    int K, N, M;
    cin >> K >> M >> N;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];
    queue<DATA> q;
    q.push(DATA(0, 0, 0));
    check[0][0][0] = true;
    int flag = 0;
    while (!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;
        int now_k = q.front().k;
        q.pop();

        if(now_r==N-1&&now_c==M-1)
        {
            cout<<dist[now_r][now_c][now_k];
            flag = 1;
            break;
        }

        if (now_k < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int next_r = now_r + HR[i];
                int next_c = now_c + HC[i];
                if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= M)
                    continue;
                if (graph[next_r][next_c] == 1 || check[next_r][next_c][now_k + 1] == true)
                    continue;
                q.push(DATA(next_r, next_c, now_k + 1));
                check[next_r][next_c][now_k + 1] = true;
                dist[next_r][next_c][now_k + 1] =  dist[now_r][now_c][now_k]+1;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int next_r = now_r + DR[i];
            int next_c = now_c + DC[i];
            if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= M)
                continue;
            if (graph[next_r][next_c] == 1 || check[next_r][next_c][now_k] == true)
                    continue;
            q.push(DATA(next_r, next_c, now_k));
            check[next_r][next_c][now_k] = true;
            dist[next_r][next_c][now_k] =  dist[now_r][now_c][now_k]+1;
        }
    }
    if(flag ==0)
        cout<<-1;
}