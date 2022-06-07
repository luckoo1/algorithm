#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DATA
{
    int R;
    int C;
    int D;
    DATA(int R, int C, int D)
    {
        this->R = R;
        this->C = C;
        this->D = D;
    }
};
//위 오른 아래 왼
int DR[4] = {-1, 0, 1, 0};
int DC[4] = {0, 1, 0, -1};
int ROW, COL;
int NW_RW, NW_CL, DIR;
vector<vector<int>> map(51, vector<int>(51));
vector<vector<bool>> check(51, vector<bool>(51, false));
queue<DATA> Q;

int main()
{
    cin >> ROW >> COL;
    cin >> NW_RW >> NW_CL >> DIR;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin >> map[i][j];
        }
    }

    Q.push(DATA(NW_RW, NW_CL, DIR));
    while (!Q.empty())
    {
        NW_RW = Q.front().R;
        NW_CL = Q.front().C;
        DIR = Q.front().D;
        check[NW_RW][NW_CL]=true;

        Q.pop();

        int flag =0;

        for(int k=0;k<4;k++)
        {
            int move_dir = (DIR-k+3)%4;
            int move_RW = NW_RW+DR[move_dir];
            int move_CL = NW_CL+DC[move_dir];

            if(move_RW<0||move_CL<0||move_RW>=ROW||move_CL>=COL)
            {
                continue;
            }
            if(map[move_RW][move_CL]==1||check[move_RW][move_CL]==true)
            {
                continue;
            }
            Q.push(DATA(move_RW,move_CL,move_dir));
            check[move_RW][move_CL]=true;
            flag = 1;
            break;
        }
        if(flag == 0)
        {
            int move_back = (DIR+2)%4;
            int back_rw = NW_RW + DR[move_back];
            int back_cl = NW_CL + DC[move_back];
            if(map[back_rw][back_cl]==1)
            {
                break;
            }
            else
            {
                Q.push(DATA(back_rw,back_cl,DIR));

            }
        }

    }

    int answer= 0;
        for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if(check[i][j]==true)
            {
                answer++;
            }
        }
    }

    cout<<answer;
}

//(x-y+3)%4