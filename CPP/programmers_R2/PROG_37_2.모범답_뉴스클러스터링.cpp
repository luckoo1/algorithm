#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(string str1, string str2)
{
    unordered_map<string, int> hash1;
    unordered_map<string, int> hash2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            hash1[str1.substr(i, 2)]++;

    for (int i = 0; i < str2.size() - 1; i++)
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            hash2[str2.substr(i, 2)]++;

    int intersection_count = 0;
    int union_count = 0;

    //여기서 교집합수는 끝남
    for (auto p : hash1)
    {
        intersection_count += min(p.second, hash2[p.first]);
    }

    for (auto p : hash1)
    {
        hash2[p.first] = max(hash2[p.first], p.second);
    }

    for (auto p : hash2)
        union_count += p.second;

    if (union_count == 0 && intersection_count == 0)
        return 65536;
    else
        return (double)intersection_count / union_count * 65536;
}
int main()
{
    string a1 = "FRANCE";
    string a2 = "french";
    string b1 = "aa1+aa2";
    string b2 = "AAAA12";

    int ans = solution(a1, a2);
    cout << ans;
}

/*
for (auto p : hash1)
{
    cout << p.first << " " << p.second << endl;
}
cout << endl;

for (auto p : hash2)
{
    cout << p.first << " " << p.second << endl;
}
*/