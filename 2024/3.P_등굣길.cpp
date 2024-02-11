#include <iostream>
#include <vector>
#define MOD (1000000007)
using namespace std;

long long dist[101][101];
bool check[101][101] = {false};

int solution(int m, int n, vector<vector<int>> puddles)
{
    int r = n;
    int c = m;
    for (int i = 0; i < puddles.size(); i++)
    {
        check[puddles[i][1] - 1][puddles[i][0] - 1] = true;
    }

    for (int i = 0; i < r; i++)
    {
        if (check[i][0] == true)
            break;
        dist[i][0] = 1;
    }
    for (int i = 0; i < c; i++)
    {
        if (check[0][i] == true)
            break;
        dist[0][i] = 1;
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (check[i][j] == true)
                continue;
            int temp_ans = ((dist[i - 1][j] % MOD) + (dist[i][j - 1] % MOD)) % MOD;
            dist[i][j] = temp_ans % MOD;
        }
    }
#if 0
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return dist[r - 1][c - 1];
}