//중복을 없애려고 set을 사용했으나 시간초과뜬다..
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

vector<int> temp_ans;

void dfs(int dep, int idx, vector<int> &nums, set<vector<int>> &answer) //set사용
{

    if (dep == 3)
    {
        if (temp_ans[0] + temp_ans[1] + temp_ans[2] == 0)
        {
            answer.insert(temp_ans); //set에 insert
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
    set<vector<int>> ans; //set사용
    dfs(0, 0, nums, ans);
    vector<vector<int>> answer(ans.begin(), ans.end());
    return answer;
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