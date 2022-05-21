#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, vector<string>> hash_map;
vector<string> temp_ans;
int ans;

bool check_unique(vector<string> vec)
{
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] == vec[i + 1])
        {
            return false; //중복임
        }
    }
    return true; //중복아님
}

bool check_id(string id, string ban)
{
    if (id.size() != ban.size())
    {
        return false;
    }
    for (int i = 0; i < ban.size(); i++)
    {
        if (ban[i] == '*')
        {
            continue;
        }
        if (ban[i] != id[i])
        {
            return false;
        }
    }
    return true;
}

void dfs(int dep)
{
    if (dep == hash_map.size())
    {
        for(auto n : temp_ans)
        {
            cout<<n<<" ";
        }
        cout<<endl;
        return;
    }
    auto iter = hash_map.begin();
    for(int i=0;i<dep;i++)
    {
        iter++;
    }
    for(int i=0;i<iter->second.size();i++)
    {
        temp_ans.push_back(iter->second[i]);
        dfs(dep+1);
        temp_ans.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            if (check_id(user_id[j], banned_id[i]) == true)
            {
                hash_map[banned_id[i]].push_back(user_id[j]);
            }
        }
    }
#if 1
    for(auto iter = hash_map.begin();iter!=hash_map.end();iter++)
    {
        for(int i=0;i<hash_map[iter->first].size();i++)
        {
            cout<<iter->first<<","<<iter->second[i]<<endl;
        }
    }
    cout<<endl;
#endif
dfs(0);


    return ans;
}
int main()
{
    ans = 0;
    //cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"}) << endl;
    // cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"}) << endl;
}
/*
******,abc123
******,frodoc
*rodo,frodo
*rodo,crodo
*rodo,frodo
*rodo,crodo
*/
/*
    set<string> not_unique;
    for (int i = 0; i < user_id.size(); i++)
    {
        not_unique.insert(user_id[i]);
    }
    user_id.clear();
    for(auto iter = not_unique.begin();iter!=not_unique.end();iter++)
    {
        user_id.push_back(*iter);
    }
    not_unique.clear();

    for (int i = 0; i < banned_id.size(); i++)
    {
        not_unique.insert(banned_id[i]);
    }
    banned_id.clear();
    for(auto iter = not_unique.begin();iter!=not_unique.end();iter++)
    {
        banned_id.push_back(*iter);
    }

    #if 0
    for(auto n: user_id)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    for(auto n: banned_id)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<endl;
    #endif
*/