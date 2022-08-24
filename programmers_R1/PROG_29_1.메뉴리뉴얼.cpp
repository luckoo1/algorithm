#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> hash_map;
bool check[11];

void dfs(int dep, int x, string temp_ans, string &str, int &size)
{
    if (dep == size)
    {
        hash_map[temp_ans] += 1;
        return;
    }
    for (int i = x; i < str.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            temp_ans.push_back(str[i]);
            dfs(dep + 1, i + 1, temp_ans, str, size);
            check[i] = false;
            temp_ans.pop_back();
        }
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    for(int i=0;i<orders.size();i++)
    {
        sort(orders[i].begin(),orders[i].end());
    }

    for (int i = 0; i < course.size(); i++)
    {
        for (int j = 0; j < orders.size(); j++)
        {
            if (orders[j].size() >= course[i])
            {
                dfs(0, 0, "", orders[j], course[i]);
            }
        }
        int max_num = 2;
        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            if (iter->second >= max_num)
            {
                max_num = iter->second;
            }
        }
        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            if (iter->second == max_num)
            {
                answer.push_back(iter->first);
            }
        }
        hash_map.clear();
        
    }
    sort(answer.begin(),answer.end());
    return answer;
}

int main()
{
    vector<string> a = solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4});
    vector<string> b = solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5});
    vector<string> c = solution({"XYZ", "XWY", "WXA"}, {2, 3, 4});

    for (auto n : a)
    {
        cout << n << " ";
    }
    cout << endl;
    for (auto n : b)
    {
        cout << n << " ";
    }
    cout << endl;
    for (auto n : c)
    {
        cout << n << " ";
    }
    cout << endl;
}