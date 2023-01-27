#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct DATA
{
    int r;
    int c;
    int z;
    DATA(int r, int c, int z)
    {
        this->r = r;
        this->c = c;
        this->z = z;
    }
};

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};
int DZ[2] = {1, -1};
int MAP[101][101][101];

int main()
{
    //freopen("Input.txt", "r", stdin);
    int R, C, Z;
    cin >> C >> R >> Z;
    queue<DATA> q;
    bool flag = false;
    for (int k = 0; k < Z; k++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> MAP[i][j][k];
                if (MAP[i][j][k] == 1)
                {
                    q.push(DATA(i, j, k));
                }
                if (MAP[i][j][k] == 0)
                {
                    flag = true;
                }
            }
        }
    }
    if (flag == false)
    {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    while (!q.empty())
    {
        int NOW_R = q.front().r;
        int NOW_C = q.front().c;
        int NOW_Z = q.front().z;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int MOVE_R = NOW_R + DR[k];
            int MOVE_C = NOW_C + DC[k];
            if (MOVE_R < 0 || MOVE_C < 0 || MOVE_R >= R || MOVE_C >= C)
                continue;
            if (MAP[MOVE_R][MOVE_C][NOW_Z]==-1||MAP[MOVE_R][MOVE_C][NOW_Z]>0)
                continue;
            q.push(DATA(MOVE_R,MOVE_C,NOW_Z));
            MAP[MOVE_R][MOVE_C][NOW_Z]=MAP[NOW_R][NOW_C][NOW_Z]+1;
        }
        for(int k=0;k<2;k++)
        {
            int MOVE_Z = NOW_Z+DZ[k];
            if(MOVE_Z<0||MOVE_Z>=Z)
                continue;
            if (MAP[NOW_R][NOW_C][MOVE_Z]==-1||MAP[NOW_R][NOW_C][MOVE_Z]>0)
                continue;
            q.push(DATA(NOW_R,NOW_C,MOVE_Z));
            MAP[NOW_R][NOW_C][MOVE_Z]=MAP[NOW_R][NOW_C][NOW_Z]+1;
        }
    }

    flag = true;
    int ans = 0;
    for (int k = 0; k < Z; k++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (MAP[i][j][k] == 0)
                {
                    flag = false;
                }
                else if(MAP[i][j][k]>ans)
                {
                    ans = MAP[i][j][k];
                }
            }
        }
    }
    if(flag == true)
        cout<<ans-1;
    else
        cout<<-1;
}