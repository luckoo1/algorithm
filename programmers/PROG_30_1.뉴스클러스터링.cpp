#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

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
    for(auto n: vec1)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    for(auto n: vec2)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    // map<string, int> hash_map1;
    // map<string, int> hash_map2;

    // vector<string> hap;
    // for (int i = 0; i < vec1.size(); i++)
    // {
    //     hash_map1[vec1[i]] += 1;
    //     hap.push_back(vec1[i]);
    // }

    // for (int i = 0; i < vec2.size(); i++)
    // {
    //     hash_map2[vec2[i]] += 1;
    //     hap.push_back(vec2[i]);
    // }

    // vector<string> gyo;
    // for (int i = 0; i < vec1.size(); i++)
    // {
    //     if (hash_map1[vec1[i]] != 0 && hash_map2[vec1[i]] != 0)
    //     {
    //         gyo.push_back(vec1[i]);
    //     }
    // }

    // sort(gyo.begin(), gyo.end());
    // sort(hap.begin(), hap.end());
    // gyo.erase(unique(gyo.begin(), gyo.end()), gyo.end());
    // hap.erase(unique(hap.begin(), hap.end()), hap.end());
    // for (auto n : gyo)
    // {
    //     cout << n << " ";
    // }
    // cout << endl;
    // for (auto n : hap)
    // {
    //     cout << n << " ";
    // }
    // cout << endl;
    // float ans = (gyo.size() * 65536 / hap.size());
    int ans = 0;
    return ans;
}

int main()
{
    cout << solution("FRANCE", "french") << endl;
    //cout << solution("handshake", "shake hands") << endl;
    //cout << solution("aa1+aa2", "AAAA12") << endl;
    //cout << solution("E=M*C^2", "e=m*c^2") << endl;
}