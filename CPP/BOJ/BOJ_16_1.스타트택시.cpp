/*
1.처음부터 손님을 못찾는경우
2.손님위치에서 목적지로 못가는 경우
BFS_check를 전역으로 뺀것이 핵심(★핵심)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int N, M, NOW_R, NOW_C, OIL;

void PRINT_VEC(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

bool sort_rule(vector<int> a, vector<int> b)
{
    if (a[0] != b[0])
    {
        if (a[0] < b[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (a[1] < b[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<vector<bool>> BFS_check(22, vector<bool>(22, false));
vector<vector<int>> BFS(vector<vector<int>> MAP, int START_R, int START_C)
{
    queue<DATA> q;

    vector<vector<int>> dist(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            BFS_check[i][j] = false;
        }
    }
    q.push(DATA(START_R, START_C));
    BFS_check[START_R][START_C] = true;

    while (!q.empty())
    {
        START_R = q.front().r;
        START_C = q.front().c;
        int now_dist = dist[START_R][START_C];
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int MOVE_R = START_R + DR[k];
            int MOVE_C = START_C + DC[k];
            if (MOVE_R < 0 || MOVE_R >= N || MOVE_C < 0 || MOVE_C >= N)
                continue;
            if (BFS_check[MOVE_R][MOVE_C] == true || MAP[MOVE_R][MOVE_C] == 1)
                continue;

            dist[MOVE_R][MOVE_C] = now_dist + 1;
            BFS_check[MOVE_R][MOVE_C] = true;
            q.push(DATA(MOVE_R, MOVE_C));
        }
    }
    return dist;
}

int main()
{
    cin >> N >> M >> OIL;

    vector<vector<int>> MAP(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    cin >> NOW_R >> NOW_C;
    vector<vector<int>> INFO(M, vector<int>(4, 0));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> INFO[i][j];
        }
    }
    sort(INFO.begin(),INFO.end(),sort_rule);

    vector<vector<int>> dist_map = BFS(MAP, NOW_R - 1, NOW_C - 1);
    vector<bool> check(M, false);
    int ok_cst = 0;

    int dist = 9999999;
    int num_cst = 9999999;
    int cst_r;
    int cst_c;
    int dest_r;
    int dest_c;

    while (ok_cst != M)
    {
        int dist = 9999999;
        for (int i = 0; i < M; i++)
        {
            if (check[i] == false)
            {
                if (dist > dist_map[INFO[i][0] - 1][INFO[i][1] - 1])
                {
                    num_cst = i;
                    cst_r = INFO[i][0] - 1;
                    cst_c = INFO[i][1] - 1;
                    dest_r = INFO[i][2] - 1;
                    dest_c = INFO[i][3] - 1;
                    dist = dist_map[INFO[i][0] - 1][INFO[i][1] - 1];
                }
            }
        }
        if (BFS_check[cst_r][cst_c] == false)/*★핵심*/
        {
            break;
        }
        check[num_cst] = true;

        OIL = OIL - dist;
        if (OIL < 0)
        {
            break;
        }

        dist_map = BFS(MAP, cst_r, cst_c);
        int dest_dist = dist_map[dest_r][dest_c];
        if (BFS_check[dest_r][dest_c] == false) /*★핵심*/
        {
            break;
        }
        OIL = OIL - dest_dist;
        if (OIL < 0)
        {
            break;
        }

        OIL = OIL + (dest_dist * 2);
        ok_cst += 1;
        dist_map = BFS(MAP, dest_r, dest_c);
    }

    if (ok_cst == M)
    {
        cout << OIL << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}