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
                           {10, 13, 16, 19, 25, 30, 35, 40},  // 10
                           {20, 22, 24, 25, 30, 35, 40},      // 20
                           {30, 28, 27, 26, 25, 30, 35, 40}}; // 30
vector<DATA> HORSE(4, DATA(0, 0));
vector<int> COMMAND(10, 0);

int answer = 0;
int temp_ans = 0;
void dfs(int dep)
{
    if (dep == 10)
    {
        return;
    }

    int cmd = COMMAND[dep];

    for (int i = 0; i < 4; i++)
    {
        int R = HORSE[i].r;
        int C = HORSE[i].c;

        if (MAP[R][C] == 10)
            R = 1;
        else if (MAP[R][C] == 20)
            R = 2;
        else if (MAP[R][C] == 30)
            R = 3;
        else if (MAP[R][C] == 40)
            continue;

        for (int j = 0; j < cmd; j++)
        {
            C = C + 1;
            temp_ans += MAP[R][C];
            if (MAP[R][C] == 40)
            {
                HORSE[i] = DATA(R,C);
            }
                break;       
        }

        dfs(dep+1);
        
        for (int j = 0; j < cmd; j++)
        {
            C = C - 1;
        }
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