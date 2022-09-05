#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void PRINT_MAP(vector<string> MAP)
{
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

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

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

vector<vector<int>> FIRE_bfs(vector<string> MAP, int N, int M)
{
    vector<vector<int>> FIRE_dist(N, vector<int>(M, 0));
    queue<DATA> q;

    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] == '*')
            {
                q.push(DATA(i, j));
                FIRE_dist[i][j]= 1;/*여기가 핵심!!*/
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
            int MR = r + DR[k];
            int MC = c + DC[k];
            if (MR < 0 || MC < 0 || MR >= N || MC >= M)
                continue;
            if (MAP[MR][MC] == '#' || FIRE_dist[MR][MC])
                continue;
            q.push(DATA(MR, MC));
            FIRE_dist[MR][MC] = FIRE_dist[r][c] + 1;
        }
    }
    return FIRE_dist;
}

void PERSON_bfs(vector<string> MAP, vector<vector<int>> FIRE_dist, int N, int M)
{
    vector<vector<int>> PERSON_dist(N, vector<int>(M, 0));
    vector<vector<int>> check(N, vector<int>(M, 0));
    queue<DATA> q;

    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] == '@')
            {
                q.push(DATA(i, j));
                PERSON_dist[i][j]= 1;/*여기가 핵심!!*/
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
            int MR = r + DR[k];
            int MC = c + DC[k];
            if (MR < 0 || MC < 0 || MR >= N || MC >= M)
            {
                cout << PERSON_dist[r][c] << endl;
                return;
            }
            if (MAP[MR][MC] == '#' || PERSON_dist[MR][MC])
                continue;
            if (PERSON_dist[r][c] + 1 >= FIRE_dist[MR][MC] && FIRE_dist[MR][MC])  /*여기가 핵심!!*/
                continue;
            q.push(DATA(MR, MC));
            PERSON_dist[MR][MC] = PERSON_dist[r][c] + 1;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}


vector<string> MAKE_MAP(int N)
{
    string MAP_info;
    vector<string> MAP;
    for (int i = 0; i < N; i++)
    {
        cin >> MAP_info;
        MAP.push_back(MAP_info);
    }
    return MAP;
}

int main()
{
    //freopen("Input.txt", "r", stdin);
    int CNT;
    int M, N;
    cin >> CNT;
    while (CNT--)
    {
        cin >> M >> N;
        vector<string> MAP = MAKE_MAP(N);
        vector<vector<int>> dist = FIRE_bfs(MAP, N, M);
        PERSON_bfs(MAP, dist, N, M);
    }
}