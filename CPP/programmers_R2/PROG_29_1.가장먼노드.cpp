#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

bool check[50001];
map<int, int> dist_map;
void bfs(vector<vector<int>> edge)
{
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));

    while (!q.empty())
    {
        int start = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (int i = 0; i < edge.size(); i++)
        {
            if (check[i] == false)
            {
                if (edge[i][0] == start)
                {
                    q.push(make_pair(edge[i][1], dist + 1));
                    check[i] = true;
                    dist_map.insert(make_pair(edge[i][1], dist + 1));
                }
                else if (edge[i][1] == start)
                {
                    q.push(make_pair(edge[i][0], dist + 1));
                    check[i] = true;
                    dist_map.insert(make_pair(edge[i][0], dist + 1));
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    bfs(edge);

    int max = 0;
    for (auto iter = dist_map.begin(); iter != dist_map.end(); iter++)
    {
        if (iter->second > max)
        {
            max = iter->second;
        }
    }
    int cnt = 0;
    for (auto iter = dist_map.begin(); iter != dist_map.end(); iter++)
    {
        if (iter->second == max)
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