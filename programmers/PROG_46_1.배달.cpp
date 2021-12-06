#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent_node[10002];
bool sort_rule(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find_parent(int node)
{
    if (parent_node[node] == node)
        return node;

    return find_parent(parent_node[node]);
}

int solution(int N, vector<vector<int>> road, int K)
{
    for (int i = 1; i <= N; i++)
        parent_node[i] = i;

    sort(road.begin(), road.end(), sort_rule);

    for (int i = 0; i < road.size(); i++)
    {
        int start = find_parent(road[i][0]);
        int end = find_parent(road[i][1]);
        int cost = road[i][2];

        if (start != end)
        {
            parent_node[end] = start;
        }
    }
}

int main()
{
    int n = 5;
    int k = 3;
    vector<vector<int>> a{{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}};
    int ans = solution(n, a, k);
    cout << "ANS : " << ans;
}