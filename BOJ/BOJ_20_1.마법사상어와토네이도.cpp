/*
BOJ_20_2.마법사상어와토네이도_R1.cpp보면
WIND_MAP만들다가 시간초과남
*/
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
void go(int R, int C,int dir, vector<vector<int>> &MAP)
{
    int now_sand = MAP[R][C];
    int wind = dir;
    int alpha = now_sand;
    int move_R;
    int move_C;

    for (int i = 0; i < 9; i++)
    {

        int plus = now_sand * persent[i];
        plus = plus / 100;
        move_R = R + spread_R[wind][i];
        move_C = C + spread_C[wind][i];
        if (move_R < 0 || move_C < 0 || move_R >= N || move_C >= N)
        {
            answer += plus;
        }
        else
        {
            MAP[move_R][move_C] += plus;
        }
        alpha -= plus;
    }
    move_R = R + DR[wind];
    move_C = C + DC[wind];
    if (move_R < 0 || move_C < 0 || move_R >= N || move_C >= N)
    {
        answer += alpha;
    }
    else
    {
        MAP[move_R][move_C] += alpha;
    }
    MAP[R][C] = 0;
}

int main()
{
    cin >> N;
    vector<vector<int>> MAP(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    int R = N / 2;
    int C = N / 2;

    int dir = 0;
    for (int i = 1; i < N; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 1; j <= i; j++)
            {
                R = R + DR[dir];
                C = C + DC[dir];
                go(R, C,dir, MAP);
            }
            dir = (dir + 1) % 4;
        }
    }
    for (int i = N-2; i >= 0; i--)
        go(0, i, 0 ,MAP);

    cout << answer;
}