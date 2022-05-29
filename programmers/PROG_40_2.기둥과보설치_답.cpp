#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool Pillar[102][102];
bool Bar[102][102];
bool check_Pillar(int x, int y)
{
    if (y == 0 || Pillar[x][y - 1]) //맨밑 or 기둥위
    {
        return true;
    }
    if (x > 0 && Bar[x - 1][y] || Bar[x][y]) //왼쪽 보위 or 오른보위
    {
        return true;
    }
    return false;
}
bool check_Bar(int x, int y)
{
    if (Pillar[x][y - 1] || Pillar[x + 1][y - 1]) //왼쪽기둥위 or 오른쪽 기둥위
    {
        return true;
    }
    if (x > 0 && Bar[x - 1][y] && Bar[x + 1][y]) //양 보 사이에 설치
    {
        return true;
    }
    return false;
}

bool check_delete(int x, int y)
{
    for (int i = max(x - 1, 0); i <= x + 1; ++i)
    {
        for (int j = y; j <= y + 1; ++j)
        {
            if (Pillar[i][j] && check_Pillar(i, j) == false)
            {
                return false;
            }
            if (Bar[i][j] && check_Bar(i, j) == false)
            {
                return false;
            }
        }
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    memset(Pillar, 0, sizeof(Pillar));
    memset(Bar, 0, sizeof(Bar));
    for (auto build : build_frame)
    {
        int x = build[0];
        int y = build[1];
        int type = build[2];
        int cmd = build[3];
        if (type == 0) //기둥
        {
            if (cmd == 1) //기둥설치
            {
                if (check_Pillar(x, y))
                {
                    Pillar[x][y] = true;
                }
            }
            else if (cmd == 0) //기둥삭제
            {
                Pillar[x][y] = false;
                if (check_delete(x, y) == false)
                {
                    Pillar[x][y] = true;
                }
            }
        }
        else if (type == 1) //보
        {
            if (cmd == 1) //보설치
            {
                if (check_Bar(x, y))
                {
                    Bar[x][y] = true;
                }
            }
            else if (cmd == 0) //보삭제
            {
                Bar[x][y] = false;
                if (check_delete(x, y) == false)
                {
                    Bar[x][y] = true;
                }
            }
        }
    }
    vector<vector<int>> answer;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (Pillar[i][j])
            {
                answer.push_back({i, j, 0});
            }
            if (Bar[i][j])
            {
                answer.push_back({i, j, 1});
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> a = solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}});
    for (auto n : a)
    {
        for (auto m : n)
        {
            cout << m << " ";
        }
        cout << endl;
    }
    vector<vector<int>> b = solution(5, {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}});
    for (auto n : b)
    {
        for (auto m : n)
        {
            cout << m << " ";
        }
        cout << endl;
    }
}