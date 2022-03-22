#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool sort_rule(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    sort(costs.begin(), costs.end(), sort_rule);
    vector<bool> check(n, false);
    for (int i = 0; i < costs.size(); i++)
    {
        int cnt_visited = 0;
        for (int j = 0; j < check.size(); j++)
        {
            if (check[j] == true)
            {
                cnt_visited += 1;
            }
        }
        if (cnt_visited == n)
        {
            break;
        }

        if (check[costs[i][0]] == false || check[costs[i][1]] == false)
        {
            check[costs[i][0]] = true;
            check[costs[i][1]] = true;
            answer += costs[i][2];
        }
    }
    return answer;
}

int main()
{
    cout << "ANSWER : "<<solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) << endl;
}
/*
섬이 2그룹으로 분리되어 연결될 경우를 고려하지 않으셨습니다.

n은 5이고, [[0,1,1],[0,2,2],[1,2,5],[1,3,3],[2,3,8],[3,4,1]] 인 경우를 생각해봅시다.
위의 알고리즘대로 라면 0-1-2 섬과 3-4 섬이 서로 연결되는 것을 확인하고, 거기서 끝납니다.

아직 하나의 연결이 부족한데, 모든 섬 방문이 끝났으니 거기서 멈춰버리고, 4를 리턴하게 되죠.
실제로는 0-1-2 섬과 3-4 섬을 이어주는 최소 비용인 [1,3,3] 연결을 수행하고 끝나야 합니다.
*/