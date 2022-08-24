#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp_array[501][501];

int bigger(int a, int b)
{
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle)
{
    dp_array[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0) //맨 왼쪽
            {
                dp_array[i][j] = triangle[i][j] + dp_array[i - 1][j];
            }
            else if (j == triangle[i].size() - 1) //맨 오른쪽
            {
                dp_array[i][j] = triangle[i][j] + dp_array[i - 1][j - 1];
            }
            else
            {
                //여기가 핵심포인트
                dp_array[i][j] = triangle[i][j] + max(dp_array[i - 1][j - 1], dp_array[i - 1][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < triangle.size(); i++)
    {
        if (dp_array[triangle.size() - 1][i] > ans)
            ans = dp_array[triangle.size() - 1][i];
    }

    return ans;
}
int main()
{
    vector<vector<int>> a{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    int ans = solution(a);
    cout << ans << endl;
}