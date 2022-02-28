#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// vector의 인자를 compare의 함수인자로 넣음
// vector의 인자가 int면 (int a, int b로 했겠지)
bool compare(pair<int, int> a, pair<int, int> b)
{

    return a.first > b.first; // play별로 내림차순
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, vector<pair<int, int>>> hash_map; //곡정보,<횟수,index>
    for (int i = 0; i < genres.size(); i++)
    {
        hash_map[genres[i]].push_back(make_pair(plays[i], i));
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        int sum = 0;
        for (int i = 0; i < hash_map[iter->first].size(); i++)
        {
            sum += hash_map[iter->first][i].first;
        }
        sort(hash_map[iter->first].begin(), hash_map[iter->first].end(), compare);
        hash_map[iter->first].push_back(make_pair(sum, 10001));
    }
    /*
    <2,0> <2,1> <2,2> <6,10001>
    <3,3> <3,10001>
    <4,4> <4,10001>
    */

    vector<pair<int, string>> sort_vector;
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        sort_vector.push_back(make_pair(hash_map[iter->first][hash_map[iter->first].size() - 1].first, iter->first));
    }
    sort(sort_vector.begin(), sort_vector.end());
    reverse(sort_vector.begin(), sort_vector.end());
    /*
    6 , a
    4 , c
    3 , b
    */

    vector<int> answer;
    for (int i = 0; i < sort_vector.size(); i++)
    {

        answer.push_back(hash_map[sort_vector[i].second][0].second);
        if (hash_map[sort_vector[i].second].size() > 2)
        {
            answer.push_back(hash_map[sort_vector[i].second][1].second);
        }
    }

    return answer;
}

int main()
{
    vector<string> a{"classic", "pop", "classic", "classic", "pop"};
    vector<int> b{500, 700, 150, 800, 2500};

    vector<string> c{"a", "a", "a", "b", "c"};
    vector<int> d{2, 2, 2, 3, 4};

    vector<int> answer = solution(c, d);
    cout << "\n";
    for (auto n : answer)
        cout << n << " ";
}