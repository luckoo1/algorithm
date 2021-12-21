/*
DP문제였다!!!!!
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find_max(int row, int col, vector<vector<int>> &land)
{
    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        if (col == i)
            continue;
        if (max < land[row][i])
            max = land[row][i];
    };
    return max;
}

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int max = find_max(i - 1, j, land);
            land[i][j] = land[i][j] + max;
        }
    }

    int answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
    return answer;
}

int main()
{
    vector<vector<int>> a{{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
    vector<vector<int>> b{{4, 3, 2, 1}, {2, 2, 2, 1}, {6, 6, 6, 4}, {8, 7, 6, 5}};
    int ans = solution(a);
    cout << ans << endl;
}