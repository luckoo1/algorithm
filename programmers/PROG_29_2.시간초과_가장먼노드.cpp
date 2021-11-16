#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

vector<int> dist_vec;
bool check[50001];
void bfs(int end, vector<vector<int>> edge)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < edge.size(); i++)
    {
        check[i] = false;
    }
    q.push(make_pair(1, 0));
    while (1)
    {
        int start = q.front().first;
        int dist = q.front().second;
        if (start == end)
        {
            dist_vec.push_back(dist);
            return;
        }
        q.pop();
        for (int i = 0; i < edge.size(); i++)
        {
            if (check[i] == false)
            {
                if (edge[i][0] == start)
                {
                    q.push(make_pair(edge[i][1], dist + 1));
                    check[i] = true;
                }
                else if (edge[i][1] == start)
                {
                    q.push(make_pair(edge[i][0], dist + 1));
                    check[i] = true;
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    for (int i = 2; i <= n; i++)
    {
        bfs(i, edge);
    }

    int max = 0;
    for (int i = 0; i < dist_vec.size(); i++)
    {
        if (dist_vec[i] > max)
        {
            max = dist_vec[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < dist_vec.size(); i++)
    {
        if (dist_vec[i] == max)
        {
            cnt += 1;
        }
    }
    return cnt;
}

int main()
{
    int a = 6;
    vector<vector<int>> b{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    int ans = solution(a, b);
    cout << ans << endl;
}