#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{

    int answer = s.size();

    for (int i = 1; i <= s.size(); i++)
    {
        string cut_string = s.substr(0, i);
        string temp_ans_string = "";
        int cnt = 1;
        for (int j = i; j <= s.size(); j += i)
        {
            if (cut_string == s.substr(j, i))
            {
                cnt += 1;
            }
            else
            {
                if (cnt == 1)
                {
                    temp_ans_string += cut_string;
                    cut_string = s.substr(j, i);
                }
                else
                {
                    temp_ans_string += to_string(cnt);
                    temp_ans_string += cut_string;

                    cut_string = s.substr(j, i);
                    cnt = 1;
                }
            }
        }

        if (s.size() % i != 0)
        {
            temp_ans_string += s.substr((s.size() / i) * i);
        }
        if (answer > temp_ans_string.size())
        {
            answer = temp_ans_string.size();
        }
    }

    return answer;
}

int main()
{
    string a = "aabbaccc";                 //7
    string b = "ababcdcdababcdcd";         //9
    string c = "abcabcdede";               //8
    string d = "abcabcabcabcdededededede"; //14
    string e = "0123456789";
    int ans = solution(a);
    cout << ans;
}