#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gems_kinds;
    map<string, int> current_gems;

    for (int i = 0; i < gems.size(); i++)
    {
        gems_kinds.insert(gems[i]);
    }
    int dist = gems.size();
    int start = 0;
    int cnt_kind_gems = gems_kinds.size();

    for (int i = 0; i < gems.size(); i++)// i를 end로 생각
    {
        current_gems[gems[i]]++;

        if (current_gems.size() == cnt_kind_gems)// current set에 모두 다 있는 경우 
        {
            // 스타트 포지션에 있는 보석이 map 크기가 2이상인 경우 map크기 1 줄인 후 스타트 포지션을 올려줌 1이면 탈출
            while (current_gems[gems[start]] > 1)
            {
                current_gems[gems[start]]--;
                start++;
            }

            // 최소 범위로 들어가 있는 경우 현재까지 발견된 최소 길이와 비교함
            if (i - start < dist)
            {
                dist = i - start;
                answer = { start + 1, i + 1 };
            }
        }
    }

    return answer;
}


int main()
{
    vector<int> a = solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    for (auto n : a)
    {
        cout << n << " ";
    }
    cout << endl;
    vector<int> b = solution({"AA", "AB", "AC", "AA", "AC"});
    for (auto n : b)
    {
        cout << n << " ";
    }
    cout << endl;
    vector<int> c = solution({"XYZ", "XYZ", "XYZ"});
    for (auto n : c)
    {
        cout << n << " ";
    }
    cout << endl;
    vector<int> d = solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});
    for (auto n : d)
    {
        cout << n << " ";
    }
    cout << endl;
}