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

vector<vector<int>> MAP = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40}, // size =22
                           {0, 13, 16, 19, 25, 30, 35, 40},                                                 // 10
                           {0, 22, 24, 25, 30, 35, 40},                                                     // 20
                           {0, 28, 27, 26, 25, 30, 35, 40}};                                                // 30

vector<int> COMMAND(10, 0);
vector<int> vec(10, 0);
int answer = 0;

void dfs(int dep)
{
    if (dep == 10)
    {
        vector<DATA> HORSE(4, DATA(0, 0));
        vector<vector<bool>> check(30, vector<bool>(30, false));
        vector<bool> finish(4, false);

        int temp_ans = 0;
        for (int i = 0; i < 10; i++)
        {
            int move_horse = vec[i];
            if (finish[move_horse] == true)
                return;

            int NOW_R = HORSE[move_horse].r;
            int NOW_C = HORSE[move_horse].c;
            int MOVE_R = NOW_R;
            int MOVE_C = NOW_C;
            bool flag = false;

            if (NOW_R == 0 && NOW_C == 5)
            {
                MOVE_R = 1;
                flag = true;
            }
            else if (NOW_R == 0 && NOW_C == 10)
            {
                MOVE_R = 2;
                flag = true;
            }
            else if (NOW_R == 0 && NOW_C == 15)
            {
                MOVE_R = 3;
                flag = true;
            }

            if (flag == true)
            {
                MOVE_C = COMMAND[i];
            }
            else
            {
                MOVE_C = MOVE_C + COMMAND[i];
            }

            if (MOVE_C >= MAP[MOVE_R].size())
            {
                finish[move_horse] = true;
                check[NOW_R][NOW_C] = false;
                continue;
            }

            if (check[MOVE_R][MOVE_C] == true)
            {
                return;
            }

            if (MAP[MOVE_R][MOVE_C] == 40)
            {
                check[0][MAP[0].size() - 1] = true;
                check[1][MAP[1].size() - 1] = true;
                check[2][MAP[2].size() - 1] = true;
                check[3][MAP[3].size() - 1] = true;
            }
            check[MOVE_R][MOVE_C] = true;
            check[NOW_R][NOW_C] = false;

            HORSE[move_horse] = DATA(MOVE_R, MOVE_C);
            temp_ans = temp_ans + MAP[MOVE_R][MOVE_C];
        }

        if (answer < temp_ans)
        {
            answer = temp_ans;

            #if 0
            cout << answer << endl;
            for (auto n : vec)
            {
                cout << n << " ";
            }
            cout << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << HORSE[i].r << "," << HORSE[i].c << endl;
            }
            for (auto n : finish)
            {
                cout << n << " ";
            }
            cout << endl;
            cout << endl;
            #endif
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vec[dep] = i;
        dfs(dep + 1);
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

#if 0
            cout << answer << endl;
            for (auto n : vec)
            {
                cout << n << " ";
            }
            cout << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << HORSE[i].r << "," << HORSE[i].c << endl;
            }
            for (auto n : finish)
            {
                cout << n << " ";
            }
            cout << endl;
            cout << endl;
#endif