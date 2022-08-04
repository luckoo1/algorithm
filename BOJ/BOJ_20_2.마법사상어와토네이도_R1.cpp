#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> DR{0, 1, 0, -1};
vector<int> DC{-1, 0, 1, 0};
int persent[9] = {1, 1, 2, 2, 5, 7, 7, 10, 10};
int spread_R[4][9] = {
    {-1, 1, -2, 2, 0, -1, 1, -1, 1},
    {-1, -1, 0, 0, 2, 0, 0, 1, 1},
    {-1, 1, -2, 2, 0, -1, 1, -1, 1},
    {1, 1, 0, 0, -2, 0, 0, -1, -1}};
int spread_C[4][9] = {
    {1, 1, 0, 0, -2, 0, 0, -1, -1},
    {-1, 1, -2, 2, 0, -1, 1, -1, 1},
    {-1, -1, 0, 0, 2, 0, 0, 1, 1},
    {-1, 1, -2, 2, 0, -1, 1, -1, 1}};
void PRINT(vector<vector<int>> MAP)
{
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int answer = 0;
void go(int R, int C, vector<vector<int>> &MAP, vector<vector<int>> WIND_MAP)
{
    int now_sand = MAP[R][C];
    int wind = WIND_MAP[R][C];
    int alpha = now_sand;
    int move_R;
    int move_C;

    for (int i = 0; i < 9; i++)
    {

        int plus = now_sand * persent[i];
        plus = plus / 100;
        move_R = R + spread_R[wind][i];
        move_C = C + spread_C[wind][i];
        if (move_R < 2 || move_C < 2 || move_R >= N + 2 || move_C >= N + 2)
        {
            answer += plus;
        }
        MAP[move_R][move_C] += plus;
        

        alpha -= plus;
    }
    move_R = R + DR[wind];
    move_C = C + DC[wind];
    if (move_R <= 1 || move_C <= 1 || move_R >= N + 2 || move_C >= N + 2)
    {
        answer += alpha;
    }
    MAP[move_R][move_C] += alpha;
    MAP[R][C] = 0;
}

int main()
{
    cin >> N;
    vector<vector<int>> MAP(N + 4, vector<int>(N + 4, 0));
    vector<vector<int>> WIND_MAP(N + 4, vector<int>(N + 4, 0));
    for (int i = 2; i < N + 2; i++)
    {
        for (int j = 2; j < N + 2; j++)
        {
            cin >> MAP[i][j];
        }
    }
    int R = (N + 4) / 2;
    int C = (N + 4) / 2;

    int dir = 0;

    for (int i = 1; i < N; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 1; j <= i; j++)
            {
                R = R + DR[dir];
                C = C + DC[dir];
                WIND_MAP[R][C] = dir;
            }
            dir = (dir + 1) % 4;
        }
    }
    for (int i = N; i >= 2; i--)
        WIND_MAP[2][i] = 0;

    R = (N + 4) / 2;
    C = (N + 4) / 2;
    for (int i = 1; i < N; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 1; j <= i; j++)
            {
                R = R + DR[dir];
                C = C + DC[dir];
                go(R, C, MAP, WIND_MAP);
            }
            dir = (dir + 1) % 4;
        }
    }
    for (int i = N; i >= 2; i--)
        go(2, i, MAP, WIND_MAP);

    cout << answer;
}