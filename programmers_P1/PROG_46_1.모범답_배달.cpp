// https://programmers.co.kr/learn/courses/30/lessons/12978
// 배달
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// vector<pair<int, int>> V[55];
vector<vector<pair<int, int>>> V(55, vector<pair<int, int>>(0));
vector<int> Dist;

void Dijkstra(int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    // queue<pair<int, int>> PQ; //queue도가능

    PQ.push(make_pair(1, 0));
    Dist[1] = 0;
    while (!PQ.empty())
    {
        int now_node = PQ.top().first;
        int now_dist = PQ.top().second;
        PQ.pop();
        for (int i = 0; i < V[now_node].size(); i++)
        {
            int next_node = V[now_node][i].first;
            int next_dist = V[now_node][i].second;
            if (Dist[next_node] > Dist[now_node] + next_dist)
            {
                Dist[next_node] = Dist[now_node] + next_dist;
                PQ.push(make_pair(next_node, next_dist));
                // PQ.push(make_pair(next_node, now_dist));
                //둘다되네 ㅠ
                //아... 사실상 now_dist는 필요가 없구나.
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K)
{
    Dist.resize(N + 1, 9999999);
    for (int i = 0; i < road.size(); i++)
    {
        int Node1 = road[i][0];
        int Node2 = road[i][1];
        int Dist = road[i][2];

        V[Node1].push_back(make_pair(Node2, Dist));
        V[Node2].push_back(make_pair(Node1, Dist));
    }

    Dijkstra(N);
    int ans = 0;
    for (int i = 1; i < Dist.size(); i++)
    {
        if (Dist[i] <= K)
            ans++;
    }
    return ans;
}

int main()
{
    int n = 5;
    int k = 3;
    vector<vector<int>> a{{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}};
    int ans = solution(n, a, k);
    cout << "ANS : " << ans;
}