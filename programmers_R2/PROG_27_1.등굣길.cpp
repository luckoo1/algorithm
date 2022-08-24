#include <vector>
#include <iostream>
using namespace std;
#define MOD 1000000007

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> dp_array(m + 1, vector<int>(n + 1, 0));
    //int dp_array[101][101]; 하면 효율성에서 틀린다?
    //int dp_array[102][102]; 하면 효율성에서 틀린다?
    for (int i = 0; i < puddles.size(); i++)
        dp_array[puddles[i][0]][puddles[i][1]] = -1;

    dp_array[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp_array[i][j] == -1)
            {
                dp_array[i][j] = 0;
            }
            else
            {
                dp_array[i][j] = dp_array[i][j] + ((dp_array[i - 1][j] + dp_array[i][j - 1]) % MOD);
            }
        }
    }

    return dp_array[m][n];
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> a = {{2, 2}};
    int ans = solution(m, n, a);
    cout << ans;
}