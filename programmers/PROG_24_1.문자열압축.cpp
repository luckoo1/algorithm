#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    if (s.size() == 1) //모서리 CASE
    {
        return 1;
    }

    int ans = 9999999;
    for (int i = 1; i <= s.size() / 2; i++)
    {
        string temp_ans = "";
        string word = s.substr(0, i);
        int cnt = 1;
        for (int j = i; j < s.size(); j += i)
        {
            if (word == s.substr(j, i))
            {
                cnt += 1;
            }
            else
            {
                if (cnt == 1)
                {
                    temp_ans += word;
                }
                else
                {
                    temp_ans = temp_ans + to_string(cnt) + word;
                }
                cnt = 1;
                word = s.substr(j, i);
            }
        }

        if (cnt == 1)
        {
            temp_ans += word;
        }
        else
        {
            temp_ans = temp_ans + to_string(cnt) + word;
        }
        
        if (temp_ans.size() < ans)
        {
            ans = temp_ans.size();
        }
    }

    return ans;
}

int main()
{
    cout << "ANSWER : 7,9,8,14,17" << endl;

    // cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    // cout << solution("abcabcdede") << endl;
    // cout << solution("abcabcabcabcdededededede") << endl;
    // cout << solution("xababcdcdababcdcd") << endl;
}