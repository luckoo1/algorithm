#include <vector>
#include <iostream>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto p : puddles)
        dp[p[0]][p[1]] = -1;

    dp[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == -1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j] + ((dp[i - 1][j] + dp[i][j - 1]) % MOD);
        }
    }

    return dp[m][n];
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> a = {{2, 2}};
    int ans = solution(m, n, a);
    cout << ans;
}
