#include <iostream>
#include <vector>
using namespace std;

int DR[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int DC[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct FISH
{
    int num;
    int dir;
    FISH(int num, int dir)
    {
        this->num = num;
        this->dir = dir;
    }
};

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

DATA find_fish(vector<vector<FISH>> MAP,int number)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(MAP[i][j].num == number)
            {
                return DATA(i,j); 
            }
        }
    }
}

void change_location(vector<vector<FISH>> &MAP,int now_r,int now_c,int move_r,int move_c)
{
    FISH temp = MAP[now_r][now_c];
    MAP[now_r][now_c] = MAP[move_r][move_c];
    MAP[move_r][move_c] = temp;
}

int main()
{
    vector<vector<FISH>> MAP(4,vector<FISH>(4,FISH(0,0)));
    int num;
    int dir;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>num>>dir;
            MAP[i][j]=FISH(num,dir-1);
        }
    }
    
    int shark_dir = MAP[0][0].dir;
    MAP[0][0].dir = 18;
    int shark_r = 0;
    int shark_c = 0;
    int answer = MAP[0][0].num;

    
    for(int i=1;i<=16;i++)
    {
        DATA where_fish =  find_fish(MAP,i);
        int now_r = where_fish.r;
        int now_c = where_fish.c;
        for(int k=0;k<8;k++)
        {
            int move_r = now_r+DR[k];
            int move_c = now_c+DC[k];
            if(move_r<0||move_r>=4||move_c<0||move_c>=4)
                continue;
            if(MAP[move_r][move_c].num = 18)
                continue;
            change_location(MAP,now_r,now_c,move_r,move_c);
            break;
        }
    }

}