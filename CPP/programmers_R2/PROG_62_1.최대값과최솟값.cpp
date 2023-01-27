#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s)
{
    vector<int> str_to_int_vec;
    string temp_str_num = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            temp_str_num += s[i];
        }
        else
        {
            str_to_int_vec.push_back(stoi(temp_str_num));
            temp_str_num = "";
        }
    }
    str_to_int_vec.push_back(stoi(temp_str_num));

    int max = *max_element(str_to_int_vec.begin(), str_to_int_vec.end());
    int min = *min_element(str_to_int_vec.begin(), str_to_int_vec.end());

    string answer = "";
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);

    return answer;
}