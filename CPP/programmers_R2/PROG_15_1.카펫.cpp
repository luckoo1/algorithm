#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow)
{
    int total = brown + yellow;
    vector<int> num;
    int j = 0;

    for (int i = 3; i < total / 2; i++)
    {
        if (total % i == 0)
        {
            num.push_back(total / i);
            num.push_back(i);
        }
    }

    vector<int> answer;
    for (int i = 0; i < num.size(); i += 2)
    {
        if (((num[i] - 2) * (num[i + 1] - 2)) == yellow)
        {
            answer.push_back(num[i]);
            answer.push_back(num[i + 1]);
            return answer;
        }
    }
}

int main()
{
    int a = 8;
    int b = 1;
    vector<int> ans = solution(a, b);
    for (auto iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
}