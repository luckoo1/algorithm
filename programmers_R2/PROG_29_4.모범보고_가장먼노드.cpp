#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool sort_rule(int a, int b)
{
    return a > b;
}
int solution(int n, vector<vector<int>> edge)
{
    vector<vector<int>> node_info(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);

    for (int i = 0; i < edge.size(); i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];

        node_info[start].push_back(end);
        node_info[end].push_back(start);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        visited[start] = true;
        for (int i = 0; i < node_info[start].size(); i++)
        {
            int end = node_info[start][i];
            if (visited[end] == false)
            {
                visited[end] = true;
                q.push(end);
                dist[end] = dist[start] + 1;
            }
        }
    }

    sort(dist.begin(), dist.end(), sort_rule);
    int biggest = dist[0];

    int cnt = 0;
    int idx = 0;
    while (1)
    {
        if (biggest == dist[idx])
        {
            cnt += 1;
            idx += 1;
            continue;
        }
        break;
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