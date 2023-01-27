#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/*
vector<string> c{"a", "a", "a", "b", "c"};
vector<int> d{2, 2, 2, 3, 4};
반례가 있다.
*/

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, vector<int>> hash_map;

    //hash_map 초기화
    for (int i = 0; i < genres.size(); i++)
    {
        hash_map[genres[i]].push_back(plays[i]);
    }

    //각 key에 value 맨뒤에 value들의 합을 넣었다.
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        int total = 0;
        for (int i = 0; i < iter->second.size(); i++)
        {
            total = total + iter->second[i];
        }
        iter->second.push_back(total);
    }

    //임시로 hash_map복사해서
    //sorted_gernes에 total순대로 넣었다.
    map<string, vector<int>> copy_hash_map(hash_map.begin(), hash_map.end());
    vector<string> sorted_gernes; //곡 길이 큰 순대로 key(장르)를 넣음

    while (!copy_hash_map.empty())
    {
        int temp_sum = 0;
        string temp_gerne = "";

        for (auto iter = copy_hash_map.begin(); iter != copy_hash_map.end(); iter++)
        {
            int genre_size = iter->second.size();
            int genre_total = iter->second[genre_size - 1];

            if (genre_total > temp_sum)
            {
                temp_sum = genre_total;
                temp_gerne = iter->first;
            }
        }
        sorted_gernes.push_back(temp_gerne);
        copy_hash_map.erase(temp_gerne);
    }

    //각 key의 value의 total을 제거해서 원복함
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        iter->second.pop_back();
    }

    //각 key의 value들을 크기 순대로 정렬
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
        reverse(iter->second.begin(), iter->second.end());
    }

    vector<int> sorted_plays; //sorted_gernes에는 total순대로 들어가있다.

    //sorted_plays에 각 key마다 제일 큰 play의 길이 2개를 선정해서 넣었다
    for (int i = 0; i < sorted_gernes.size(); i++)
    {
        int first = hash_map[sorted_gernes[i]][0];
        sorted_plays.push_back(first);
        if (hash_map[sorted_gernes[i]].size() == 1) //play가 하나면 1개만 넣게했다.
        {
            continue;
        }
        int second = hash_map[sorted_gernes[i]][1];
        sorted_plays.push_back(second);
    }

    vector<int> ans;
    //sorted_plays는 각 key마다 제일 큰 play의 길이 넣은 곳이다
    for (int i = 0; i < sorted_plays.size(); i++)
    {
        int length = sorted_plays[i];

        int j = plays.size();

        for (int j = 0; j < plays.size(); j++)
        {
            if (plays[j] == length)
            {
                ans.push_back(j); //idex를 넣기
            }
        }
    }
    return ans;
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
    cout << endl;
}