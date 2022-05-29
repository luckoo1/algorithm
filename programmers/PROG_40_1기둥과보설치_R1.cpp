#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool Pillar[102][102];
bool Bar[102][102];

bool check_Pillar(int row, int col)
{
    if (row == 0) //맨 밑에 있음
    {
        return true;
    }
    if (Pillar[row - 1][col]) //밑에 기둥이 있음
    {
        return true;
    }
    if (col > 0 && Bar[row][col - 1]) //왼쪽에 보가 있음
    {
        return true;
    }
    if (Bar[row][col]) //오른쪽에 보가 있음
    {
        return true;
    }
    return false;
}

bool check_Bar(int row, int col)
{
    if (Pillar[row - 1][col]) //왼쪽 기둥 위
    {
        return true;
    }
    if (Pillar[row - 1][col + 1]) //오쪽 기둥 위
    {
        return true;
    }
    if (col > 0 && Bar[row][col + 1] && Bar[row][col - 1]) //보 사이
    {
        return true;
    }
    return false;
}
//[row][col]이 없을때 주변에것 설치가능?을 물어봄
bool check_delete(int row, int col)   //★★★★★★★★★★★★★★★
{ 
    for (int i = row; i <= row + 1; ++i) //int i = max(row - 1, 0)도 가능
    {
        for (int j = max(col - 1, 0); j <= col + 1; ++j)
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
    memset(Pillar, false, sizeof(Pillar));
    memset(Bar, false, sizeof(Bar));
    for (int i = 0; i < build_frame.size(); i++)
    {
        int row = build_frame[i][1];
        int col = build_frame[i][0];
        int type = build_frame[i][2]; // 1:보 0:기둥
        int cmd = build_frame[i][3];  // 1:설치 0:삭제

        if (cmd == 1) //설치
        {
            if (type == 0) //기둥설치
            {
                if (check_Pillar(row, col))
                {
                    Pillar[row][col] = true;
                }
            }
            else if (type == 1) //보 설치
            {
                if (check_Bar(row, col))
                {
                    Bar[row][col] = true;
                }
            }
        }
        else if (cmd == 0) //삭제
        {
            if (type == 0) //기둥삭제
            {
                Pillar[row][col] = false;
                if (check_delete(row, col) == false)
                {
                    Pillar[row][col] = true;
                }
            }
            else if (type == 1) //보삭제
            {
                Bar[row][col] = false;
                if (check_delete(row, col) == false)
                {
                    Bar[row][col] = true;
                }
            }
        }
    }

    vector<vector<int>> answer;

    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (Pillar[i][j])
            {
                answer.push_back({j, i, 0});
            }
            if (Bar[i][j])
            {
                answer.push_back({j, i, 1});
            }
        }
    }

    return answer;
}

// int main()
// {
// vector<vector<int>> a = solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}});
// for (auto n : a)
// {
//     for (auto m : n)
//     {
//         cout << m << " ";
//     }
//     cout << endl;
// }
//         vector<vector<int>> b = solution(5, {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}});
//         for (auto n : b)
//         {
//             for (auto m : n)
//             {
//                 cout << m << " ";
//             }
//             cout << endl;
//         }
// }