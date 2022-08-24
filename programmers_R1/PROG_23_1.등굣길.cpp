/*
m과 n이 어디 위치에 있는지 언제나 방심하지 말자!
*/
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < puddles.size(); i++)
    {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] == -1)
            {
                dp[i][j] = 0;  //continue해서 틀렸었음
            }
            else
            {
                dp[i][j] = dp[i][j] + ((dp[i - 1][j] + dp[i][j - 1]) % MOD);
            }
        }
    }

    return dp[n][m];
}