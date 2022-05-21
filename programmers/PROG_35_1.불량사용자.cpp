#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, vector<string>> hash_map;
vector<string> temp_ans;
set<string> ans_set;
int banned_size;
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

void dfs(int dep, vector<string> &banned_id)
{
    if (dep == banned_size)
    {
        if (check_unique(temp_ans) == true)
        {
            string temp_str = "";
            sort(temp_ans.begin(),temp_ans.end());
            for (auto n : temp_ans)
            {
                temp_str += n;
                temp_str += " ";
            }
            ans_set.insert(temp_str);
        }
        return;
    }
    for (int i = 0; i < hash_map[banned_id[dep]].size(); i++)
    {
        temp_ans.push_back(hash_map[banned_id[dep]][i]);
        dfs(dep + 1, banned_id);
        temp_ans.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    banned_size = banned_id.size();

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
    dfs(0, banned_id);
    for(auto iter = ans_set.begin();iter!= ans_set.end();iter++)
    {
        cout<<*iter<<endl;
    }

#if 0
    for(auto iter = hash_map.begin();iter!=hash_map.end();iter++)
    {
        for(int i=0;i<hash_map[iter->first].size();i++)
        {
            cout<<iter->first<<","<<iter->second[i]<<endl;
        }
    }
    cout<<endl;
#endif
    return ans;
}
int main()
{
    ans = 0;
    // cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}) << endl;
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