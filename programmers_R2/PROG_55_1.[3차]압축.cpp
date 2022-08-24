#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    map<string, int> hash_map;

    int value = 1;
    for (int i = 0; i < 26; i++)
    {
        char temp_ch = 'A' + i;
        string temp_str = "";
        temp_str.push_back(temp_ch);
        hash_map[temp_str] = value;
        value += 1;
    }

    string temp_str = "";

    for (int i = 0; i < msg.size(); i++)
    {
        temp_str += msg[i];
        auto find_key = hash_map.find(temp_str);
        if (find_key != hash_map.end())
            continue;
        else
        {
            hash_map[temp_str] = value;
            value += 1;

            temp_str.pop_back();
            answer.push_back(hash_map[temp_str]);

            temp_str = "";
            i = i - 1;
        }
    }
    answer.push_back(hash_map[temp_str]);
    return answer;
}
int main()
{
    string a = "KAKAO";
    vector<int> ans1 = solution(a);
    for (auto n : ans1)
        cout << n << " ";
    cout << endl;

    // string b = "TOBEORNOTTOBEORTOBEORNOT";
    // vector<int> ans2 = solution(b);
    // for (auto n : ans2)
    //     cout << n << " ";
    // cout << endl;

    // string c = "ABABABABABABABAB";
    // vector<int> ans3 = solution(c);
    // for (auto n : ans3)
    //     cout << n << " ";
    // cout << endl;
}

// for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
// {
//     cout << iter->first << " : " << iter->second << endl;
// }