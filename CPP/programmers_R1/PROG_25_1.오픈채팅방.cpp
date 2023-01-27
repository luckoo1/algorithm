#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record)
{
    map<string, string> hash;
    vector<vector<string>> slice;
    vector<string> one_line_slice;
    vector<string> ans;

    for (int i = 0; i < record.size(); i++)
    {
        string temp_slice = "";
        for (int j = 0; j < record[i].size(); j++)
        {
            if (record[i][j] != ' ')
            {
                temp_slice.push_back(record[i][j]);
            }
            else
            {
                one_line_slice.push_back(temp_slice);
                temp_slice = "";
            }
        }
        one_line_slice.push_back(temp_slice);
        slice.push_back(one_line_slice);
        one_line_slice.clear();
    }

    for (int i = 0; i < slice.size(); i++)
    {
        if (slice[i][0] == "Enter" || slice[i][0] == "Change")
        {
            hash[slice[i][1]] = slice[i][2];
        }
    }
    // for (auto iter = hash.begin(); iter != hash.end(); iter++)
    // {
    //     cout << iter->first << "," << iter->second << endl;
    // }

    for (int i = 0; i < slice.size(); i++)
    {
        if (slice[i][0] == "Change")
        {
            continue;
        }
        if (slice[i][0] == "Enter")
        {
            ans.push_back(hash[slice[i][1]]+"님이 들어왔습니다.");
        }
        if (slice[i][0] == "Leave")
        {
            ans.push_back(hash[slice[i][1]]+"님이 나갔습니다.");
        }
    }

    return ans;
}