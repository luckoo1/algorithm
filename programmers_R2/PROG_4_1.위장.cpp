#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> hash_map;
    for (int i = 0; i < clothes.size(); i++)
    {
        for (int j = 0; j < clothes[i].size() - 1; j++)
        {
            hash_map[clothes[i][clothes[i].size() - 1]]++;
        }
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        answer = answer * ((iter->second) + 1);
    }
    return answer - 1;
}

int main()
{
    vector<vector<string>> a = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string>> b = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    int ans = solution(a);
    cout << "ANSWER : " << ans << endl;
    ans = solution(b);
    cout << "ANSWER : " << ans << endl;
}
/*
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, vector<string>> hash_map;
    for (int i = 0; i < clothes.size(); i++)
    {
        for (int j = 0; j < clothes[i].size() - 1; j++)
        {
            hash_map[clothes[i][clothes[i].size() - 1]].push_back(clothes[i][j]);
        }
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        answer = answer * ((hash_map[iter->first].size()) + 1);
    }
    return answer - 1;
}
*/