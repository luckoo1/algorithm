#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int DR[5] = {0, 0, 0, -1, 1};
int DC[5] = {0, 1, -1, 0, 0};
/*오,왼,위,아래*/

struct DATA
{
    int num;
    int r;
    int c;
    int dir;
    DATA(int num, int r, int c, int dir)
    {
        this->num = num;
        this->r = r;
        this->c = c;
        this->dir = dir;
    }
};

bool sort_rule(vector<int> a, vector<int> b)
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

int change_dir(int dir)
{
    if (dir == 1)
    {
        return 2;
    }
    else if (dir == 2)
    {
        return 1;
    }
    else if (dir == 3)
    {
        return 4;
    }
    else if (dir == 4)
    {
        return 3;
    }
}

int N, K;
vector<DATA> CHESS_LOC[14][14];

void move_horse(vector<vector<int>> MAP, vector<vector<int>> &HORSE)
{
    sort(HORSE.begin(), HORSE.end(), sort_rule);
    for (int i = 0; i < K; i++)
    {
        int num = HORSE[i][0];
        int now_R = HORSE[i][1];
        int now_C = HORSE[i][2];
        int dir = HORSE[i][3];

        int move_R = now_R + DR[dir];
        int move_C = now_C + DC[dir];

        if (move_R < 1 || move_C < 1 || move_R > N || move_R > N || MAP[move_R][move_C] == 2)
        {
            dir = change_dir(dir);
            for (int i = 0; i < CHESS_LOC[now_R][now_C].size(); i++)
            {
                if (CHESS_LOC[now_R][now_C][i].num == num)
                {
                    CHESS_LOC[now_R][now_C][i].dir = dir;
                    continue;
                }
            }
        }
        else if (MAP[move_R][move_C] == 1) /*빨간색*/
        {
            int idx;
            for (int i = 0; i < CHESS_LOC[now_R][now_C].size(); i++)
            {
                if (CHESS_LOC[now_R][now_C][i].num == num)
                {
                    idx = i;
                    break;
                }
            }
            for (int i = CHESS_LOC[now_R][now_C].size() - 1; i >= idx; i--)
            {
                CHESS_LOC[move_R][move_C].push_back(DATA(CHESS_LOC[now_R][now_C][i].num,
                                                         move_R,
                                                         move_C,
                                                         CHESS_LOC[now_R][now_C][i].dir));
            }
            int sz = CHESS_LOC[now_R][now_C].size()-idx;
            for(int i=0;i<sz;i++)
            {
                CHESS_LOC[now_R][now_C].pop_back();
            }
        }
        else if (MAP[move_R][move_C] == 0) /*흰색*/
        {
            int idx;
            for (int i = 0; i < CHESS_LOC[now_R][now_C].size(); i++)
            {
                if (CHESS_LOC[now_R][now_C][i].num == num)
                {
                    idx = i;
                    break;
                }
            }
            for (int i = idx; i < CHESS_LOC[now_R][now_C].size(); i++)
            {
                CHESS_LOC[move_R][move_C].push_back(DATA(CHESS_LOC[now_R][now_C][i].num,
                                                         move_R,
                                                         move_C,
                                                         CHESS_LOC[now_R][now_C][i].dir));
            }
            int sz = CHESS_LOC[now_R][now_C].size()-idx;
            for(int i=0;i<sz;i++)
            {
                CHESS_LOC[now_R][now_C].pop_back();
            }
        }
    }
    HORSE.clear();
    vector<int> temp;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=0;k<CHESS_LOC[i][j].size();k++)
            {
                temp.clear();
                temp.push_back(CHESS_LOC[i][j][k].num);
                temp.push_back(CHESS_LOC[i][j][k].r);
                temp.push_back(CHESS_LOC[i][j][k].c);
                temp.push_back(CHESS_LOC[i][j][k].dir);
                HORSE.push_back(temp);
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout<<CHESS_LOC[i][j].size()<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    cin >> N >> K;
    vector<vector<int>> MAP(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> HORSE(K, vector<int>(4, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        HORSE[i][0] = i + 1;
        for (int j = 1; j <= 3; j++)
        {
            cin >> HORSE[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int num = HORSE[i][0];
        int now_R = HORSE[i][1];
        int now_C = HORSE[i][2];
        int dir = HORSE[i][3];
        CHESS_LOC[now_R][now_C].push_back(DATA(num, now_R, now_C, dir));
    }

    cout<<endl;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout<<HORSE[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"after move"<<endl;
    move_horse(MAP, HORSE);
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout<<HORSE[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"after move"<<endl;
    move_horse(MAP, HORSE);
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout<<HORSE[i][j]<<" ";
        }
        cout<<endl;
    }
}

#if 0
    cout<<endl;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cout<<HORSE[i][j]<<" ";
        }
        cout<<endl;
    }
#endif