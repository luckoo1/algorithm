#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> rs;            //set을 이용해서 중복제거
    sort(nums.begin(), nums.end()); //정렬하고
    int sz = nums.size();

    for (int i = 0; i < sz - 2; i++)
    {
        int front = i + 1; //j는 앞
        int back = sz - 1; //k는 맨뒤

        while (front < back)
        {
            int sum = nums[i] + nums[front] + nums[back];
            if (sum == 0)
            {
                vector<int> tmp(3);
                tmp[0] = nums[i];
                tmp[1] = nums[front];
                tmp[2] = nums[back];
                rs.insert(tmp);

                front++;
                back--;
            }
            //sum을 통해서 이렇게 접근하는 것이 핵심
            else if (sum > 0)
            {
                back--;
            }
            else if (sum < 0)
            {
                front++;
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