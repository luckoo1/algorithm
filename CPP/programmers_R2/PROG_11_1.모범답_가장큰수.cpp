#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool sort_rule(string &a, string &b)
{
    return (a + b > b + a);
}

string solution(vector<int> numbers)
{
    vector<string> word;

    for (int i = 0; i < numbers.size(); i++)
    {
        word.push_back(to_string(numbers[i]));
    }

    sort(word.begin(), word.end(), sort_rule);

    if (word[0] == "0") //모서리 케이스
    {
        return "0";
    }

    string answer = "";
    for (auto iter = word.begin(); iter != word.end(); iter++)
    {
        answer += *iter;
    }
    return answer;
}

int main()
{
    vector<int> a1{3, 30, 34, 5, 9};
    string ans = solution(a1);
    cout << ans;
}