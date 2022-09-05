#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int MAP[302];
int dp[302];
int N;
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> MAP[i];
    }
    dp[1] = MAP[1];
    dp[2] = MAP[1] + MAP[2];
    dp[3] = max(MAP[1] + MAP[3],MAP[2] + MAP[3]);
    for (int i = 4; i <= N; i++)
    {
        dp[i] = max(MAP[i] + MAP[i - 1] + dp[i - 3],
                    MAP[i] + dp[i - 2]);
    }
    cout<<dp[N];
}
