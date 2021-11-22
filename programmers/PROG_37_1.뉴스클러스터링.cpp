//5 7 9 10 11
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
vector<string> cut_two_word(string str)
{
    string word = "";
    vector<string> cut_vec;
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] >= 'A' && str[i + 1] <= 'Z')
        {
            word += str[i];
            word += str[i + 1];
            cut_vec.push_back(word);
            word = "";
        }
    }
    return cut_vec;
}

string str_setting(string a)
{
    string str = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = a[i] - ('a' - 'A');
            str += a[i];
        }
        else
        {
            str += a[i];
        }
    }
    return str;
}

int solution(string str1, string str2)
{
    str1 = str_setting(str1);
    str2 = str_setting(str2);
    vector<string> cut_str1 = cut_two_word(str1);
    vector<string> cut_str2 = cut_two_word(str2);
    /*
    집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.
    문제를 똑바로 파악하자!
    */
    if (cut_str1.size() == 0 && cut_str2.size() == 0) //이거 처음에 ||해서 틀림
    {
        return 65536;
    }

    //같은 원소가 뭐가 있는지 확인해보기
    vector<string> same;
    vector<string> copy_cut_str1{cut_str1.begin(), cut_str1.end()};
    vector<string> copy_cut_str2{cut_str2.begin(), cut_str2.end()};
    sort(copy_cut_str1.begin(), copy_cut_str1.end());
    sort(copy_cut_str2.begin(), copy_cut_str2.end());
    copy_cut_str1.erase(unique(copy_cut_str1.begin(), copy_cut_str1.end()), copy_cut_str1.end());
    copy_cut_str2.erase(unique(copy_cut_str2.begin(), copy_cut_str2.end()), copy_cut_str2.end());

    for (int i = 0; i < copy_cut_str1.size(); i++)
    {
        for (int j = 0; j < copy_cut_str2.size(); j++)
        {
            if (copy_cut_str1[i] == copy_cut_str2[j])
            {
                same.push_back(copy_cut_str1[i]);
                break;
            }
        }
    }

    if (same.size() == 0)
    {
        return 0;
    }

    vector<int> check1(cut_str1.size(), 0);
    vector<int> check2(cut_str2.size(), 0);

    int same_str1 = 0;
    for (int i = 0; i < same.size(); i++)
    {
        for (int j = 0; j < cut_str1.size(); j++)
        {
            if (same[i] == cut_str1[j])
            {
                check1[j] = 1;
                same_str1 += 1;
            }
        }
    }

    int same_str2 = 0;
    for (int i = 0; i < same.size(); i++)
    {
        for (int j = 0; j < cut_str2.size(); j++)
        {
            if (same[i] == cut_str2[j])
            {
                check2[j] = 1;
                same_str2 += 1;
            }
        }
    }

    unordered_map<string, int> str1_map;
    unordered_map<string, int> str2_map;

    for (int i = 0; i < cut_str1.size(); i++)
    {
        str1_map[cut_str1[i]] += 1;
    }

    for (int i = 0; i < cut_str2.size(); i++)
    {
        str2_map[cut_str2[i]] += 1;
    }

    // for (auto iter = str1_map.begin(); iter != str1_map.end(); iter++)
    // {
    //     cout << iter->first << " " << iter->second << endl;
    // }
    // cout << endl;
    // for (auto iter = str2_map.begin(); iter != str2_map.end(); iter++)
    // {
    //     cout << iter->first << " " << iter->second << endl;
    // }
    // cout << endl;
    int cnt_gyo_jiphap = 0;
    int cnt_hap_jiphap = 0;

    for (int i = 0; i < same.size(); i++)
    {

        int a = str1_map[same[i]];
        int b = str2_map[same[i]];

        if (a == b)
        {
            cnt_gyo_jiphap += a;
            cnt_hap_jiphap += b;
        }
        else
        {
            cnt_gyo_jiphap += min(a, b);
            cnt_hap_jiphap += max(a, b);
        }
    }

    int union_str1 = cut_str1.size() - same_str1;
    int union_str2 = cut_str2.size() - same_str2;
    cnt_hap_jiphap += union_str1;
    cnt_hap_jiphap += union_str2;

    // cout << cnt_gyo_jiphap << endl;
    // cout << cnt_hap_jiphap << endl;
    // cout << endl;
    // for (int i = 0; i < cut_str1.size(); i++)
    // {
    //     if (check1[i] == 0)
    //     {
    //         cnt_hap_jiphap += str1_map[cut_str1[i]];
    //     }
    // }

    // for (int i = 0; i < cut_str2.size(); i++)
    // {
    //     if (check2[i] == 0)
    //     {
    //         cnt_hap_jiphap += str2_map[cut_str2[i]];
    //     }
    // }

    double temp = (double)cnt_gyo_jiphap / (double)cnt_hap_jiphap;
    int ans = temp * 65536;

    return ans;
}

int main()
{
    string a1 = "FRANCE";
    string a2 = "frenchchch";
    string b1 = "aa1+aa2";
    string b2 = "AAAA12";

    int ans = solution(a1, a2);
    cout << ans;
}

/*
    //같은 원소가 뭐가 있는지 확인해보기
    vector<string> same;
    vector<string> copy_cut_str1{cut_str1.begin(), cut_str1.end()};
    vector<string> copy_cut_str2{cut_str2.begin(), cut_str2.end()};
    sort(copy_cut_str1.begin(), copy_cut_str1.end());
    sort(copy_cut_str2.begin(), copy_cut_str2.end());
    copy_cut_str1.erase(unique(copy_cut_str1.begin(), copy_cut_str1.end()), copy_cut_str1.end());
    copy_cut_str2.erase(unique(copy_cut_str2.begin(), copy_cut_str2.end()), copy_cut_str2.end());

    for (int i = 0; i < copy_cut_str1.size(); i++)
    {
        for (int j = 0; j < copy_cut_str2.size(); j++)
        {
            if (copy_cut_str1[i] == copy_cut_str2[j])
            {
                same.push_back(copy_cut_str1[i]);
                break;
            }
        }
    }
*/