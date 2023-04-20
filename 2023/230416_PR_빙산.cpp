//BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
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

int check_separate(vector<vector<int>> graph)
{
    queue<DATA> q;
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] != 0)
            {
                q.push(DATA(i,j));
                graph[i][j]=0;
                flag = 1;
            }
            if(flag ==1)
                break;
        }
        if(flag ==1)
            break;
    }

    if(flag ==0)
        return 1;
    
    while(!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int next_r = now_r+DR[k];
            int next_c = now_c+DC[k];
            if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= M)
                continue;
            if(graph[next_r][next_c] == 0)
                continue;
            graph[next_r][next_c] = 0;
            q.push(DATA(next_r,next_c));
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(graph[i][j]!=0)
                return 2;
        }
    }
    return 0;

}

int main()
{
    //freopen("Input.txt", "r", stdin);
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    int ans = 0;
    int flag = 0;
    while (1)
    {
        if (check_separate(graph)==2)
        {
            flag = 1;
        }
        else if(check_separate(graph)==1)
        {
            flag = 1;
            ans = 0;
        }
        if (flag == 1)
            break;

        vector<vector<int>> ice_graph(N, vector<int>(M, 0));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (graph[i][j] != 0)
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int side_r = i + DR[k];
                        int side_c = j + DC[k];
                        if (side_r < 0 || side_c < 0 || side_r >= N || side_c >= M)
                            continue;
                        if (graph[side_r][side_c] == 0)
                            cnt++;
                    }
                    ice_graph[i][j] = cnt;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                graph[i][j] = graph[i][j] - ice_graph[i][j];
                if (graph[i][j] < 0)
                {
                    graph[i][j] = 0;
                }
            }
        }
        ans += 1;
    }

    cout << ans;
}