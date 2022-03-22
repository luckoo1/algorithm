#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> ans; //1, 2, 3, 2, 3
    for (int i = 0; i < prices.size(); i++)
    {
        int temp_ans = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            temp_ans += 1;
            if (prices[i] > prices[j])
                break;
        }
        ans.push_back(temp_ans);
    }
    return ans; //4, 3, 1, 1, 0
}

int main()
{
    vector<int> a{1, 2, 3, 2, 3};
    vector<int> ans = solution(a);
    for (auto n : ans)
    {
        cout << n << " ";
    }
}