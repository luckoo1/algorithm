#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string to_binary(int num)
{
    string binary_string = "";
    while (num >= 2)
    {
        int a = num / 2;
        int b = num % 2;
        binary_string += to_string(b);
        num = a;
    }
    binary_string += to_string(num);

    reverse(binary_string.begin(), binary_string.end());
    return binary_string;
}

vector<int> solution(string s)
{
    int do_cnt = 0;
    int total_removed_zero = 0;
    while (s != "1")
    {
        int cnt_one = 0;
        string remove_zero = "";
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
            {
                cnt_one += 1;
                remove_zero += "1";
            }
            else
            {
                total_removed_zero += 1;
            }

        s = to_binary(cnt_one);
        do_cnt += 1;
    }

    vector<int> ans{do_cnt, total_removed_zero};
    return ans;
}