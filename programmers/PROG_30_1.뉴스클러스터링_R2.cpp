#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#define MOD 65536
using namespace std;

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int solution(string str1, string str2)
{
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] = str1[i] - ('a' - 'A');
        }
    }

    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z')
        {
            str2[i] = str2[i] - ('a' - 'A');
        }
    }
    vector<string> vec1;
    vector<string> vec2;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string temp = "";
        if (str1[i] >= 'A' && str1[i] <= 'Z' && str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
        {
            temp.push_back(str1[i]);
            temp.push_back(str1[i + 1]);
            vec1.push_back(temp);
            temp.clear();
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string temp = "";
        if (str2[i] >= 'A' && str2[i] <= 'Z' && str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
        {
            temp.push_back(str2[i]);
            temp.push_back(str2[i + 1]);
            vec2.push_back(temp);
            temp.clear();
        }
    }
    if (vec1.empty() || vec2.empty())
    {
        return MOD;
    }
    // for(auto n:vec1)
    // {
    //     cout<<n<<" ";
    // }
    // cout<<endl;
    // for(auto n:vec2)
    // {
    //     cout<<n<<" ";
    // }
    // cout<<endl;

    map<string, int> hash_map1;
    map<string, int> hash_map2;

    vector<string> hap;

    for (int i = 0; i < vec1.size(); i++)
    {
        hash_map1[vec1[i]] += 1;
        hap.push_back(vec1[i]);
    }

    for (int i = 0; i < vec2.size(); i++)
    {
        hash_map2[vec2[i]] += 1;
        hap.push_back(vec2[i]);
    }
    vector<string> gyo;
    for (auto iter = hash_map1.begin(); iter != hash_map1.end(); iter++)
    {
        if (hash_map2[iter->first] != 0)
        {
            int cnt = min(hash_map1[iter->first], hash_map1[iter->first]);
            for (int i = 0; i < cnt; i++)
            {
                gyo.push_back(iter->first);
            }
        }
    }

    sort(hap.begin(), hap.end());
    hap.erase(unique(hap.begin(), hap.end()), hap.end());

    vector<string> real_hap;
    for (int i = 0; i < hap.size(); i++)
    {
        if (hash_map1[hap[i]] != 0 && hash_map2[hap[i]] != 0)
        {
            int cnt = max(hash_map1[hap[i]], hash_map2[hap[i]]);
            for (int j = 0; j < cnt; j++)
            {
                real_hap.push_back(hap[i]);
            }
        }
        else
        {
            real_hap.push_back(hap[i]);
        }
    }
    // for(auto n: gyo)
    // {
    //     cout<<n<<" ";
    // }
    // cout<<endl;
    // for(auto n: real_hap)
    // {
    //     cout<<n<<" ";
    // }
    // cout<<endl;

    return (gyo.size()*MOD/real_hap.size());
}