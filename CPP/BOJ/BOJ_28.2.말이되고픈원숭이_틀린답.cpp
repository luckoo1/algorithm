#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct DATA
{
    int r;
    int c;
    int cnt;
    int ability;
    DATA(int r, int c, int cnt,int ability)
    {
        this->r = r;
        this->c = c;
        this->cnt = cnt;
        this->ability = ability;
    }
};
int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int HORSE_R[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int HORSE_C[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
bool visited[201][201][31];

int main()
{
    freopen("Input.txt", "r", stdin);
    int CHANGE_HORSE;
    int M, N; //(COL수,ROW수)
    cin >> CHANGE_HORSE;
    cin >> M >> N;
    vector<vector<int>> MAP(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }

    queue<DATA> q;
    q.push(DATA(0, 0, 0, 0));
    for(int i = 0; i <= CHANGE_HORSE; i++){
        visited[0][0][i] = true;
    }
    while (!q.empty())
    {

        int NOW_R = q.front().r;
        int NOW_C = q.front().c;
        int NOW_CNT = q.front().cnt;
        int NOW_ability = q.front().ability;
        q.pop();
        if (NOW_R == N - 1 && NOW_C == M - 1)
        {
            cout << NOW_CNT;
            return 0;
        }
        if (NOW_ability < CHANGE_HORSE)
        {
            for (int k = 0; k < 8; k++)
            {
                int MOVE_R = NOW_R + HORSE_R[k];
                int MOVE_C = NOW_C + HORSE_C[k];

                if (MOVE_R < 0 || MOVE_C < 0 || MOVE_R >= N || MOVE_C >= M)
                    continue;
                if (MAP[MOVE_R][MOVE_C] == 0 && visited[MOVE_R][MOVE_C][NOW_ability + 1] == false)
                {
                    visited[MOVE_R][MOVE_C][NOW_ability + 1] = true;
                    q.push(DATA(MOVE_R, MOVE_C, NOW_CNT++,NOW_ability++));
                }
            }
        }

        for (int k = 0; k < 4; k++)
        {
            int MOVE_R = NOW_R + DR[k];
            int MOVE_C = NOW_C + DC[k];
            if (MOVE_R < 0 || MOVE_C < 0 || MOVE_R >= N || MOVE_C >= M)
                continue;
            if (MAP[MOVE_R][MOVE_C] == 0 && visited[MOVE_R][MOVE_C][NOW_ability] == false)
            {
                visited[MOVE_R][MOVE_C][NOW_ability] = true;
                q.push(DATA(MOVE_R, MOVE_C, NOW_CNT++,NOW_ability));
            }
        }
    }
    cout << -1;
}