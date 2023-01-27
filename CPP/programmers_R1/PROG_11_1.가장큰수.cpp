#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool sort_rule(string a,string b)
{
    return a+b > b+a;
}
string solution(vector<int> numbers)
{
    /*
    모서리 케이스
    {0,0,0,0,0,0}인경우
    "0"으로 return
    */
    int check_zero = 0;
    for (int i = 0; i < numbers.size();i++)
    {
       if(numbers[i]==0)
       {
           check_zero += 1;
       }
       else
       {
           break;
       }
    }

    if (numbers.size() == check_zero)
    {
        return "0";
    }

    string answer = "";
    vector<string> int_to_str;
    for (int i = 0; i < numbers.size();i++)
    {
        int_to_str.push_back(to_string(numbers[i]));
    }

    sort(int_to_str.begin(), int_to_str.end(), sort_rule);

    for (int i = 0; i < int_to_str.size(); i++)
    {
        answer+=int_to_str[i];
    }
    return answer;
}

int main()
{
    vector<int> a{6, 10, 2};
    cout << solution(a) << endl;
    vector<int> b{3, 30, 34, 5, 9};
    cout << solution(b) << endl;
}