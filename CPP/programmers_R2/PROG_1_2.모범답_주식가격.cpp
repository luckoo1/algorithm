//크러스컬 알고리즘(Kruskal Algorithm)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int set[101];

bool sort_rule(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find_parent(int node)
{
    if (set[node] == node)
        return node;

    return find_parent(set[node]);
    //return set[node] = find_parent(set[node]);
    //왜 위와같이 적엇을까??
}

int solution(int n, vector<vector<int>> costs)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        set[i] = i;

    sort(costs.begin(), costs.end(), sort_rule);

    for (int i = 0; i < costs.size(); i++)
    {
        int start = find_parent(costs[i][0]);
        int end = find_parent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end)
        {
            ans += cost;
            set[end] = start;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> a{{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};
    int b = 4;
    int ans = solution(b, a);
    cout << endl;
    cout << ans;
}