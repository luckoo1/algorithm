//크러스컬 알고리즘(Kruskal Algorithm)
// PROG_20_1.섬연결하기.cpp
// https://lipcoder.tistory.com/entry/%EC%84%AC-%EC%97%B0%EA%B2%B0%ED%95%98%EA%B8%B0-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4
// https://mjmjmj98.tistory.com/76

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int parent[101];

bool sort_rule(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find_parent(int node)
{
    if (parent[node] == node)
        return node;

    return find_parent(parent[node]);
    // return parent[node] = find_parent(parent[node]);
    //왜 위와같이 적엇을까??
}

int solution(int n, vector<vector<int>> costs)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(costs.begin(), costs.end(), sort_rule);

    for (int i = 0; i < costs.size(); i++)
    {
        int start = find_parent(costs[i][0]);
        int end = find_parent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end)
        {
            ans += cost;
            parent[end] = start;
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