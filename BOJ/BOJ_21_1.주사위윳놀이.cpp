#include <iostream>
#include <vector>
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

vector<vector<int>> MAP = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
                           {0, 13, 16, 19, 25, 30, 35, 40},  // 10
                           {0, 22, 24, 25, 30, 35, 40},      // 20
                           {0, 28, 27, 26, 25, 30, 35, 40}}; // 30
vector<vector<bool>> check(4,vector<bool>(22,false));
vector<DATA> HORSE(4, DATA(0, 0));
vector<int> COMMAND(10, 0);
vector<int> vec(10,0);
int answer = 0;
void dfs(int dep)
{
    if (dep == 10)
    {
        int temp_ans = 0;
        for(int i=0;i<10;i++)
        {
            int move_horse = vec[i];
            int R = HORSE[move_horse].r;
            int C = HORSE[move_horse].c;
            int MOVE_R = R + COMMAND[i];
            int MOVE_C = C;

            if(check[MOVE_R][C]==true)
                break;
            
            if(MAP[MOVE_R][C]==10)
                MOVE_C = 1;   
            else if(MAP[MOVE_R][C]==20)
                MOVE_C = 2;
            else if(MAP[MOVE_R][C]==30)
                MOVE_C = 3;

            check[MOVE_R][MOVE_C]=true;
            check[R][C]=false;
        
            HORSE[move_horse]=DATA(MOVE_R,MOVE_C);

        }
        return;
    }

    for(int i=0;i<4;i++)
    {
        vec[dep]=i;
        dfs(dep+1);        
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> COMMAND[i];
    }
    dfs(0);
    cout << answer;
}