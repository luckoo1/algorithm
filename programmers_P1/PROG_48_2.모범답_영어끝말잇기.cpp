#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    map<string, int> hash_map;
    int wrong_idx = 0;
    hash_map[words[0]] = 1;
    for (int i = 1; i < words.size(); i++)
    {
        hash_map[words[i]] += 1;
        if (hash_map[words[i]] == 2 || words[i - 1][words[i - 1].size() - 1] != words[i][0])
        {
            return {i % n + 1, i / n + 1};
        }
    }

    return {0, 0};
}

int main()
{
    int n1 = 3;
    vector<string> a{"tank", "kick", "know",
                     "wheel", "land", "dream",
                     "mother", "robot", "tank"};
    int n2 = 5;
    vector<string> b{"hello", "observe", "effect", "take", "either",
                     "recognize", "encourage", "ensure", "establish", "hang",
                     "gather", "refer", "reference", "estimate", "executive"};

    int n3 = 2;
    vector<string> c{"hello", "one", "even", "never", "now", "world", "draw"};

    vector<int> answer = solution(n3, c);
    // for (auto n : answer)
    //     cout << n << " ";
}