#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

bool check[11];
string temp_course = "";
unordered_map<string, int> course_cnt;
vector<string> ans;

void find_max_value()
{
    int temp_max = 0;
    for (auto iter = course_cnt.begin(); iter != course_cnt.end(); iter++)
    {
        if (temp_max < iter->second)
            temp_max = iter->second;
    }
    if (temp_max > 1)
    {
        for (auto iter = course_cnt.begin(); iter != course_cnt.end(); iter++)
        {
            if (iter->second == temp_max)
                ans.push_back(iter->first);
        }
    }
    course_cnt.clear();
}

void map_setting(string course_key)
{
    if (course_cnt[course_key] == 0)
    {
        course_cnt[course_key] = 1;
    }
    else
    {
        course_cnt[course_key] += 1;
    }
}

void dfs(int dep, int k, string word, int max)
{
    if (dep == max)
    {
        map_setting(temp_course);
        return;
    }
    for (int i = k; i < word.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            temp_course.push_back(word[i]);
            dfs(dep + 1, i + 1, word, max);
            check[i] = false;
            temp_course.pop_back();
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    for (int i = 0; i < orders.size(); i++)
    {
        string s = orders[i];
        sort(s.begin(), s.end());
        orders[i] = s;
    }

    for (int i = 0; i < course.size(); i++)
    {
        for (int j = 0; j < orders.size(); j++)
        {
            dfs(0, 0, orders[j], course[i]);
        }
        find_max_value();
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<string> a{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<string> b{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<string> c{"XYZ", "XWY", "WXA"};

    vector<int> d{2, 3, 4};
    vector<int> e{2, 3, 5};
    vector<int> f{2, 3, 4};

    vector<string> ans = solution(c, f);

    for (auto str : ans)
        cout << str << " ";
}
/*
if (cnt_course["abc"] == 0)
{
    cout << "fsadfasd" << endl;
}
cout << cnt_course.size() << endl;
for (auto iter = cnt_course.begin(); iter != cnt_course.end(); iter++)
{
    cout << iter->first << "," << iter->second << endl;
}
*/