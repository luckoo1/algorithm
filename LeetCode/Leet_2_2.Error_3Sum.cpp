//중복된걸 없애주지 못한다 ㅠㅠ
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> temp_ans;

void dfs(int dep, int idx, vector<int> &nums, vector<vector<int>> &answer)
{

    if (dep == 3)
    {
        if (temp_ans[0] + temp_ans[1] + temp_ans[2] == 0)
        {
            answer.push_back(temp_ans);
        }
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        temp_ans.push_back(nums[i]);
        dfs(dep + 1, i + 1, nums, answer);
        temp_ans.pop_back();
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    dfs(0, 0, nums, ans);

    return ans;
}

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> answer = threeSum(a);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}