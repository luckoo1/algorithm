#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
/*
이건 뭐.... 수학문제같다
경우의수를 잘 생각해야 한다.
headgear가 2개
eyewear가 1개이다
그럼
(2개+안입는경우)*(1개+안입는경우) = 6
6에서 아무것도 안입는 경우 1을 빼야한다.
*/
int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> hash_map;
    for (int i = 0; i < clothes.size(); i++)
    {
        hash_map[clothes[i][1]]++;
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        answer = answer * ((iter->second) + 1);
    }
    answer -= 1;
    return answer;
}

int main()
{
    vector<vector<string>> a = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    vector<vector<string>> b = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    int ans = solution(b);

    cout << "\nANSWER = : " << ans;
}