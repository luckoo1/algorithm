#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
    if (a.size() < b.size())
    {
        return true;
    }
    return false;
}

bool check[100001];
vector<int> solution(string s)
{

    vector<string> string_number;

    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            string num = "";
            i++;
            while (s[i] != '}')
            {
                num += s[i];
                i++;
            }
            string_number.push_back(num);
        }
    }

    sort(string_number.begin(), string_number.end(), cmp);

    vector<vector<int>> number;
    vector<int> temp_num_vec;

    for (int i = 0; i < string_number.size(); i++)
    {
        temp_num_vec.clear();
        string temp_num = "";
        for (int j = 0; j < string_number[i].size(); j++)
        {
            if (string_number[i][j] == ',')
            {
                temp_num_vec.push_back(stoi(temp_num));
                temp_num = "";
                continue;
            }
            temp_num += string_number[i][j];
            if (j == string_number[i].size() - 1)
            {
                temp_num_vec.push_back(stoi(temp_num));
            }
        }
        number.push_back(temp_num_vec);
    }

    vector<int> answer;

    for (int i = 0; i < number.size(); i++)
    {
        for (int j = 0; j < number[i].size(); j++)
        {
            if (check[number[i][j]] == false)
            {
                answer.push_back(number[i][j]);
                check[number[i][j]] = true;
            }
        }
    }

    return answer;
}

int main()
{
    string a = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    string b = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    string c = "{{20,111},{111}}";
    string d = "{{123}}";
    string e = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

    vector<int> ans = solution(a);
    for (auto n : ans)
    {
        cout << n << " ";
    }
}
