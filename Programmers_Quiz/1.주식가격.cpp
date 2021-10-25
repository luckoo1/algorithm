#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] <= prices[j])
            {
                temp += 1;
            }
            else
            {
                temp += 1;
                break;
            }
        }
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
    vector<int> v{1, 2, 99, 2, 3};
    vector<int> ans = solution(v);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
}