#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> rs;
    sort(nums.begin(), nums.end());
    int i, j, k;
    int n = nums.size();
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> tmp(3);
                tmp[0] = nums[i];
                tmp[1] = nums[j];
                tmp[2] = nums[k];
                rs.push_back(tmp);
                j++;
                k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
        }
    }
    vector<vector<int>> result(rs.begin(), rs.end());
    return result;
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