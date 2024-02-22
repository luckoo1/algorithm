//1. 상어가가 있었던자리 또 갈수 있다. ex) 하하상,하상우
//2. 갈곳없으면(예를들어 어딜가도 sum이 0) 상상상 sum=-1로 해결

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define PRINT (1)

struct DATA
{
    int r;
    int c;
    int dir;
    DATA(int r, int c, int dir)
    {
        this->r = r;
        this->c = c;
        this->dir = dir;
    }
};

int DR[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int DC[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int SR[4] = {-1, 0, 1, 0};
int SC[4] = {0, -1, 0, 1};
//상,좌,우,하
vector<int> grp[4][4];
vector<int> move_grp[4][4];
vector<int> dir;
vector<int> max_dir;

int sm_f_check[4][4] = {0};
int cnt_f[4][4] = {0};

int N, S, sr, sc;
int sum = -1;

int idx =0;

void f_move()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grp[i][j].size() == 0)
                continue;
            for (int k = 0; k < grp[i][j].size(); k++)
            {
                int dir = grp[i][j][k];
                int mr = i + DR[dir];
                int mc = j + DC[dir];
                int cnt = 0;
                while ((mr < 0 || mc < 0 || mr >= 4 || mc >= 4) || (mr == sr && mc == sc)||sm_f_check[mr][mc]>0)
                {
                    dir = dir - 1;
                    if (dir < 0)
                        dir = 7;
                    mr = i + DR[dir];
                    mc = j + DC[dir];

                    cnt+=1;
                    if(cnt==8)
                        break;
                }
                if(cnt == 8)
                {
                    move_grp[i][j].push_back(grp[i][j][k]);
                }
                else
                {
                    move_grp[mr][mc].push_back(dir);
                }

            }
        }
    }
    
}

void make_cnt_fish()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cnt_f[i][j] = move_grp[i][j].size();

}


void find_shark_move(int dep, int r, int c, int temp_sum)
{
    if (dir.size() == 3)
    {
        if (temp_sum > sum)
        {
            max_dir.clear();
            for (int i = 0; i < 3; i++)
            {
                max_dir.push_back(dir[i]);
            }
            
            sum = temp_sum;
        }
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int mr = r + SR[k];
        int mc = c + SC[k];
        if (mr < 0 || mc < 0 || mr >= 4 || mc >= 4)
            continue;

        int tmep_cnt = cnt_f[mr][mc];

        dir.push_back(k);
        temp_sum += cnt_f[mr][mc];
        cnt_f[mr][mc] = 0;

        find_shark_move(dep + 1, mr, mc, temp_sum);

        dir.pop_back();
        temp_sum -= tmep_cnt;
        cnt_f[mr][mc] = tmep_cnt;

    }
}

void smell_fish()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(sm_f_check[i][j]>0)
                sm_f_check[i][j] = sm_f_check[i][j]-1;
        }
    }

    int r = sr;
    int c = sc;
    for (int i = 0; i < max_dir.size(); i++)
    {
        r = r + SR[max_dir[i]];
        c = c + SC[max_dir[i]];
        if(move_grp[r][c].size()>0)
        {
            sm_f_check[r][c] = 2;
            move_grp[r][c].clear();
        }
    }
    sr = r;
    sc = c;
}

void copy_fish()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == sr && j == sc)
                continue;
            if(grp[i][j].empty()&&move_grp[i][j].empty())
                continue;
            for(int k=0;k<move_grp[i][j].size();k++)
            {   
                grp[i][j].push_back(move_grp[i][j][k]);
            }
        }
    }
}

void clear_move_grp()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            move_grp[i][j].clear();
        }
    }
}

int main()
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        int r, c, dir;
        cin >> r >> c >> dir;
        grp[r - 1][c - 1].push_back(dir - 1);
    }
    cin >> sr >> sc;
    sr = sr - 1;
    sc = sc - 1;
    for(int i=0;i<S;i++)
    {
        f_move();
        sum=-1;
        make_cnt_fish();
        find_shark_move(0, sr, sc, 0);
        smell_fish();
        copy_fish();
        clear_move_grp();
    }

    int ans = 0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(grp[i][j].size()>0)
                ans +=grp[i][j].size();
        }
    }
    cout<<ans;

}