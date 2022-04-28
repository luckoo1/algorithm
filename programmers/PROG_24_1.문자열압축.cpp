#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = 99999999;
    vector<string> vec;
    for (int i = 0; i < s.size(); i += 2)
    {
        vec.push_back(s.substr(i, 1));
    }
    string word = vec[0];
    string temp_str = "";
    int cnt = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (word == vec[i])
        {
            cnt += 1;
        }
        else
        {
            if (cnt != 1)
            {
                temp_str = temp_str + (to_string(cnt) + word);
                cnt = 1;
            }
            else
            {
                temp_str = temp_str + word;
                word = vec[i];
            }
        }

    }
    cout<<temp_str<<endl;

    return answer;
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