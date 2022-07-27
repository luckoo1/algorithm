#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
vector<vector<int>> MAP(22, vector<int>(22, 0));
vector<int> dice{2, 1, 5, 6, 4, 3};

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

void PRINT_VEC(vector<vector<int>> vec)
{
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

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

vector<int> rotate_left()
{
    vector<int> temp = dice;
    temp[1] = dice[5];
    temp[3] = dice[4];
    temp[4] = dice[1];
    temp[5] = dice[3];
    return temp;
}
vector<int> rotate_right()
{
    vector<int> temp = dice;
    temp[1] = dice[4];
    temp[3] = dice[5];
    temp[4] = dice[3];
    temp[5] = dice[1];
    return temp;
}
vector<int> rotate_up()
{
    vector<int> temp = dice;
    temp[0] = dice[1];
    temp[1] = dice[2];
    temp[2] = dice[3];
    temp[3] = dice[0];
    return temp;
}
vector<int> rotate_down()
{
    vector<int> temp = dice;
    temp[0] = dice[3];
    temp[1] = dice[0];
    temp[2] = dice[1];
    temp[3] = dice[2];
    return temp;
}

void bfs()
{
    queue<DATA> q;
    vector<vector<bool>> check(22, vector<bool>(22, false));
    for (int i = 1; i <= N; i++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                check[i][j] = false;
            }
        }
        for (int j = 1; j <= M; j++)
        {
            if (check[i][j] == false)
            {
                q.push(DATA(i, j));
                check[i][j] = true;
                int number = MAP[i][j];
                int cnt = 1;
                while (!q.empty())
                {
                    int start_R = q.front().r;
                    int start_C = q.front().c;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int move_R = start_R + DR[4];
                        int move_C = start_C + DC[4];
                        if (move_R < 1 || move_C < 1 || move_R > N || move_C > N)
                            continue;
                        if (check[move_R][move_C] == true)
                            continue;
                        if (MAP[move_R][move_C] != number)
                            continue;
                        q.push(DATA(move_R, move_C));
                        check[move_R][move_C] = true;
                        cnt += 1;
                    }
                }

                for (int i = 1; i <= N; i++)
                {
                    for (int j = 1; j <= M; j++)
                    {
                        MAP[i][j] = MAP[i][j] * cnt;
                    }
                }
                cout<<endl;
                for (int i = 1; i <= N; i++)
                {
                    for (int j = 1; j <= M; j++)
                    {
                        cout<<check[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<number<<endl;
                cout<<endl;
            }
        }
    }
}
int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
        }
    }

    bfs();
    PRINT_VEC(MAP);
}