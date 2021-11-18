#include <vector>
#include <queue>
#include <st
#include <iostream>
using namespace std;
//문제에서 전역변수를 함수안에서 초기화 하라는게 있어서 check를 solution함수내에서 초기화 했다.
bool check[101][101];

void bfs(int i, int j, int num, int m, int n, vector<vector<int>> picture, int &max_size_of_one_area)
{
    queue<pair<int, int>> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    q.push(make_pair(i, j));
    int cnt = 1;

    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        check[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            if (new_i < 0 || new_j < 0 || new_i >= m || new_j >= n)
                continue;
            if (picture[new_i][new_j] == num && check[new_i][new_j] == false)
            {
                q.push(make_pair(new_i, new_j));
                check[new_i][new_j] = true;
                cnt += 1;
            }
        }
    }
    if (cnt > max_size_of_one_area)
    {
        max_size_of_one_area = cnt;
    }
    return;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            check[i][j] = false;
        }
    }
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < picture.size(); i++)
    {
        for (int j = 0; j < picture[i].size(); j++)
        {
            if (picture[i][j] != 0 && check[i][j] == false)
            {
                bfs(i, j, picture[i][j], m, n, picture, max_size_of_one_area);
                number_of_area += 1;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    int a = 6;
    int b = 4;
    vector<vector<int>> c{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    vector<int> ans = solution(a, b, c);
    cout << ans[0] << " " << ans[1];
}