#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    map<string, int> hash_map;
    int wrong_idx = 0;
    for (int i = 0; i < words.size(); i++)
    {
        hash_map[words[i]] += 1;
        if (hash_map[words[i]] == 2)
        {
            wrong_idx = i;
            break;
        }

        if (i == words.size() - 1)
            break;

        char end = words[i][words[i].size() - 1];
        if (end != words[i + 1][0])
        {
            wrong_idx = i + 1;
            break;
        }
    }

    if (wrong_idx == 0)
    {
        vector<int> ans = {0, 0};
        return ans;
    }

    wrong_idx += 1;
    int a = wrong_idx % n;
    int b = wrong_idx / n;

    if (a == 0)
        a = n;
    else
        b += 1;
    vector<int> ans{a, b};
    return ans;
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