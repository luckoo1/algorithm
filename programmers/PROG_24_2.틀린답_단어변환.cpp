#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool diff_one(string a, string b)
{
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            diff += 1;
    }
    if (diff == 1)
        return true;
    else
        return false;
}

bool check[51] = {false};
int temp_ans = 9999999;
bool flag = false;

void dfs(int dep, string begin, string target, vector<string> words)
{
    if (begin == target)
    {
        if (dep < temp_ans)
            temp_ans = dep;
        cout << "temp_ans : " << temp_ans << endl;
        flag = true;
        return;
    }

    if (dep == words.size())
    {
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (diff_one(begin, words[i]) == true && check[i] == false)
        {
            check[i] = true;
            begin = words[i]; //이걸하면 왜 틀릴까...???
            dfs(dep + 1, begin, target, words);
            check[i] = false;
        }
    }
}
// cout << dep + 1 << " " << begin << " " << words[i] << endl;

int solution(string begin, string target, vector<string> words)
{
    dfs(0, begin, target, words);
    int ans = temp_ans;
    return ans;
}

int main()
{
    string a = "hit";
    string b = "cog";
    vector<string> c{"hot", "dot", "dog", "lot", "log", "cog"};
    int ans = solution(a, b, c);
    cout << ans << endl;
}