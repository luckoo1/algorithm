#include <iostream>
#include <vector>
using namespace std;

int dist[501][501];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int solution(vector<vector<int>> triangle)
{

    dist[0][0] = triangle[0][0];

    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (j == 0)
            {
                dist[i][j] = triangle[i][j] + dist[i-1][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                dist[i][j] = triangle[i][j] + dist[i - 1][j - 1];
            }
            else
            {
                int big_num = max(dist[i - 1][j], dist[i - 1][j - 1]);
                dist[i][j] = triangle[i][j] + big_num;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < triangle[triangle.size()-1].size(); i++)
    {
        if(ans<dist[triangle.size()-1][i])
            ans = dist[triangle.size()-1][i];
    }

    #if 0
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    #endif

    return ans;
}