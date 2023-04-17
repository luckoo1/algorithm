#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int dist[1001][1001][11] = {0};

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
    vector<string> str_vec;
    //freopen("Input.txt", "r", stdin);
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        string temp_str;
        cin >> temp_str;
        str_vec.push_back(temp_str);
    }

    vector<vector<int>> graph(N, vector<int>(M, 0));
    for (int i = 0; i < str_vec.size(); i++)
    {
        for (int j = 0; j < str_vec[i].size(); j++)
        {
            int num = str_vec[i][j];
            graph[i][j] = num - 48;
        }
    }
    int flag = 0;
    queue<DATA> q;
    q.push(DATA(0, 0, 0));
    dist[0][0][0] = 1;
    while (!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;
        int now_k = q.front().k;
        q.pop();

        if(now_r==N-1&&now_c==M-1)
        {
            cout<<dist[now_r][now_c][now_k]<<endl;
            flag = 1;
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            int move_r = now_r + DR[k];
            int move_c = now_c + DC[k];
            if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= M)
                continue;

            if (now_k < K)
            {
                if (graph[move_r][move_c] == 1)
                {
                    if (dist[move_r][move_c][now_k + 1] != 0)
                        continue;
                    dist[move_r][move_c][now_k + 1] = dist[now_r][now_c][now_k] + 1;
                    q.push(DATA(move_r, move_c, now_k + 1));
                }
            }

            if (graph[move_r][move_c] == 1)
                continue;
            if (dist[move_r][move_c][now_k] != 0)
                continue;
                q.push(DATA(move_r, move_c, now_k));
                dist[move_r][move_c][now_k] = dist[now_r][now_c][now_k] + 1;
        }
    }
    if(flag == 0)
        cout<<-1<<endl;
}