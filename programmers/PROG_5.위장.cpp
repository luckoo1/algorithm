#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    multimap<string, string> multi_map;

    for (int i = 0; i < clothes.size(); i++)
    {
        multi_map.insert(pair(clothes[i][1], clothes[i][0]));
    }

    return answer;
}

int main()
{
    vector<vector<string>> a = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string>> b = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    int ans = solution(a);

    cout << "\nANSWER = : " << ans;
}