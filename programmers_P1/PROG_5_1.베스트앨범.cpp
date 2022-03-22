#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, vector<int>> hash_map;

    //hash_map 초기화
    for (int i = 0; i < genres.size(); i++)
    {
        hash_map[genres[i]].push_back(plays[i]);
    }

    //각 key에 value "맨뒤에 value들의 total"을 넣었다.
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

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        //각 key의 value의 total을 제거해서 원복함
        iter->second.pop_back();
        //각 key의 value들을 크기 순대로 정렬
        sort(iter->second.begin(), iter->second.end());
        reverse(iter->second.begin(), iter->second.end());
        //제일 큰거 2개만 남기고 pop_back()을 했다.
        while (iter->second.size() > 2)
        {
            iter->second.pop_back();
        }
    }

    vector<int> ans;
    bool check[10001] = {false};

    for (int i = 0; i < sorted_gernes.size(); i++)
    {
        vector<int> big_play = hash_map[sorted_gernes[i]];

        for (int j = 0; j < big_play.size(); j++)
        {
            int length = big_play[j];
            for (int k = 0; k < plays.size(); k++)
            {
                if (length == plays[k] && check[k] == false)
                {
                    ans.push_back(k);
                    check[k] = true;
                    break;
                }
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
}