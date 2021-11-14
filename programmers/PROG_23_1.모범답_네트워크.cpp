#include <vector>
#include <iostream>
using namespace std;

bool dfs(vector<vector<int>> &computers, int n)
{
    if (!computers[n][n]) //이미 방문한 노드라면 리턴(재귀함수 탈출조건)
        return false;

    computers[n][n] = 0; //방문했다고 변경하기

    for (int i = 0; i < computers.size(); i++) //노드수만큼 반복
    {
        if (computers[n][i]) //연결된 노드가 있다면 재귀
            dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] && dfs(computers, i)) //방문하지 않은 노드라면 dfs탐색후 answer증가
            answer++;
    }
    return answer;
}

int main()
{
    int a = 4;
    vector<vector<int>> b{{1, 1, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 0, 1, 1}}; //틀린예제
    // int a = 7;
    // vector<vector<int>> b{
    //     {1, 1, 1, 0, 0, 0, 0},
    //     {1, 1, 0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 1, 1, 0, 0},
    //     {0, 1, 0, 1, 1, 1, 0},
    //     {0, 0, 0, 0, 1, 1, 0},
    //     {0, 0, 0, 0, 0, 0, 1}};

    int ans = solution(a, b);
    cout << ans;
}

/*
print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]), 2)
print(solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]), 1)
print(solution(3, [[1, 0, 1], [0, 1, 0], [1, 0, 1]]), 2)
print(solution(4, [[1, 1, 0, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 0, 1, 1]]), 1)
print(solution(4, [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]), 4)
*/