#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M;

struct DATA
{
    int r;
    int c;
    int t;
    DATA(int r, int c, int t)
    {
        this->r = r;
        this->c = c;
        this->t = t;
    }
};

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

int water_dist[51][51];
int dist[51][51];

bool no_graph(int r, int c)
{
    if (r < 0 || c < 0 || r >= N || c >= M)
        return true;
    return false;
}

int main()
{
    //freopen("Input.txt", "r", stdin);
    cin >> N >> M;
    vector<string> graph;
    for (int i = 0; i < N; i++)
    {
        string temp_str;
        cin >> temp_str;
        graph.push_back(temp_str);
    }
    int final_r;
    int final_c;
    queue<DATA> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == '*')
            {
                q.push(DATA(i, j, 0));
            }
            if (graph[i][j]=='D')
            {
                final_r = i;
                final_c = j;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (graph[i][j] == 'S')
                q.push(DATA(i, j, 1));

    while (!q.empty())
    {
        int now_r = q.front().r;
        int now_c = q.front().c;
        int type = q.front().t;
        q.pop();
        if (type == 0) // 물
        {
            for (int k = 0; k < 4; k++)
            {
                int move_r = now_r + DR[k];
                int move_c = now_c + DC[k];
                if (no_graph(move_r, move_c))
                    continue;
                if (graph[move_r][move_c] == 'X' || graph[move_r][move_c] == 'D')
                    continue;
                if (water_dist[move_r][move_c] != 0)
                    continue;
                q.push(DATA(move_r, move_c, type));
                water_dist[move_r][move_c] = water_dist[now_r][now_c] + 1;
            }
        }
        else if (type == 1)
        {
            for (int k = 0; k < 4; k++)
            {
                int move_r = now_r + DR[k];
                int move_c = now_c + DC[k];
                if (no_graph(move_r, move_c))
                    continue;
                if (graph[move_r][move_c] == 'X')
                    continue;
                if (dist[move_r][move_c] != 0)
                    continue;
                if (water_dist[move_r][move_c] != 0)
                    continue;
                q.push(DATA(move_r, move_c, type));
                dist[move_r][move_c] = dist[now_r][now_c] + 1;
            }
        }
    }
    if(dist[final_r][final_c]==0)
        cout<<"KAKTUS";
    else
        cout<<dist[final_r][final_c];
    #if 0
    cout<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << water_dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    #endif
}