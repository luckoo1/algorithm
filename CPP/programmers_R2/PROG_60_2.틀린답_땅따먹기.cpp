/*
총 2가지 방법으로 풀려다 틀림
1. brute force려하다가 시간초과
*/

#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
void dfs(int col, int temp_ans, int dep, vector<vector<int>> &vec)
{
    if (dep == vec.size())
    {
        if (temp_ans > ans)
            ans = temp_ans;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (col == i)
            continue;
        temp_ans += vec[dep][i];
        dfs(i, temp_ans, dep + 1, vec);
        temp_ans -= vec[dep][i];
    }
}
int solution(vector<vector<int>> land)
{
    for (int i = 0; i < 4; i++)
        dfs(i, land[0][i], 1, land);
    return ans;
}

int main()
{
    vector<vector<int>> a{{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
    int ans = solution(a);
    cout << ans << endl;
}

/*
총 2가지 방법으로 풀려다 틀림
1. brute force려하다가 시간초과
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int max = *max_element(land[0].begin(), land[0].end());
    int max_index = max_element(land[0].begin(), land[0].end()) - land[0].begin();

    for (int i = 1; i < land.size(); i++)
    {
        int now_max_index = max_element(land[i].begin(), land[i].end()) - land[i].begin();

        if (max_index == now_max_index)
        {
            land[i].erase(max_element(land[i].begin(), land[i].end()));
            max += *max_element(land[i].begin(), land[i].end());
            int second_max_index = max_element(land[i].begin(), land[i].end()) - land[i].begin();
            if (second_max_index <= max_index)
                max_index = second_max_index + 1;
        }
        else
        {
            max += *max_element(land[i].begin(), land[i].end());
            max_index = now_max_index;
        }
    }

    return max;
}