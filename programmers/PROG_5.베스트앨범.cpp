#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, vector<int>> hash_map;

    for (int i = 0; i < genres.size(); i++)
    {
        hash_map[genres[i]].push_back(plays[i]);
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        int total = 0;
        for (int i = 0; i < iter->second.size(); i++)
        {
            total = total + iter->second[i];
        }
        iter->second.push_back(total);
        //각 key에 value 맨뒤에 value들의 합을 넣었다.
    }

    map<string, vector<int>> copy_hash_map(hash_map.begin(), hash_map.end());
    vector<string> sorted_gernes;

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
        iter->second.pop_back();
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
        reverse(iter->second.begin(), iter->second.end());
    }

    vector<int> sorted_plays;

    for (int i = 0; i < sorted_gernes.size(); i++)
    {
        int first = hash_map[sorted_gernes[i]][0];
        int second = hash_map[sorted_gernes[i]][1];
        sorted_plays.push_back(first);
        sorted_plays.push_back(second);
    }

    vector<int> ans;

    for (int i = 0; i < sorted_plays.size(); i++)
    {
        int length = sorted_plays[i];

        for (int j = 0; j < plays.size(); j++)
        {
            cout << j << endl;
            if (plays[j] == length)
            {
                ans.push_back(j);
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> a{"classic", "pop", "classic", "classic", "pop"};
    vector<int> b{500, 600, 150, 800, 2500};

    vector<int> answer = solution(a, b);
    cout << "\n";
    for (auto n : answer)
        cout << n << endl;
}