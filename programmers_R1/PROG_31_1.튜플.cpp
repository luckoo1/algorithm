#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

bool sort_rule(string a, string b)
{

    int a_cnt = 0;
    int b_cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ',')
        {
            a_cnt++;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == ',')
        {
            b_cnt++;
        }
    }

    if (a_cnt < b_cnt)
    {
        return true;
    }
    return false;
}

bool check[100001];
vector<int> solution(string s)
{
    vector<string> str_num_vec;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            i++;
            string temp_str = "";
            while (s[i] != '}')
            {
                temp_str.push_back(s[i]);
                i++;
            }
            str_num_vec.push_back(temp_str);
        }
    }
    sort(str_num_vec.begin(), str_num_vec.end(), sort_rule);

    vector<int> answer;
    for (int i = 0; i < str_num_vec.size(); i++)
    {
        string temp_str = "";
        
        for (int j = 0; j < str_num_vec[i].size(); j++)
        {
            if (str_num_vec[i][j] != ',')
            {
                temp_str.push_back(str_num_vec[i][j]);
            }
            else
            {
                if (check[stoi(temp_str)] == false)
                {
                    check[stoi(temp_str)] = true;
                    answer.push_back(stoi(temp_str));
                }
                temp_str.clear();
            }
        }
        if (check[stoi(temp_str)] == false)
        {
            check[stoi(temp_str)] = true;
            answer.push_back(stoi(temp_str));
        }
    }

    return answer;
}
int main()
{
    vector<int> a = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (auto n : a)
        cout << n << " ";
    cout << endl;
    vector<int> b = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    for (auto n : b)
        cout << n << " ";
    cout << endl;
    vector<int> c = solution("{{20,111},{111}}");
    for (auto n : c)
        cout << n << " ";
    cout << endl;
    vector<int> d = solution("{{123}}");
    for (auto n : d)
        cout << n << " ";
    cout << endl;
    vector<int> e = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for (auto n : e)
        cout << n << " ";
    cout << endl;
}