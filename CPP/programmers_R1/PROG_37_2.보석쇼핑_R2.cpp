#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> kind_gems{gems.begin(),gems.end()};
    map<string,int> hash_map;

    int cnt_kind_gems = kind_gems.size();
    int start = 0;
    int dist = gems.size();
    for(int i=0;i<gems.size();i++)
    {
        hash_map[gems[i]]+=1;

        if(hash_map.size()==cnt_kind_gems)
        {
            while(hash_map[gems[start]]>1)
            {
                hash_map[gems[start]]-=1;
                start++;
            }
            if(i-start<dist)
            {
                dist = i-start;
                answer={start+1,i+1};
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