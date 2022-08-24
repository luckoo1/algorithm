#include <string>
#include <vector>
#include <iostream>
using namespace std;

string ans;
string word;

bool check[1000001] = {false};

void dfs(int dep, int idx, int size, vector<char> &one_word)
{
    if (dep == size)
    {
        if (ans < word)
            ans = word;
        return;
    }

    for (int i = idx; i < one_word.size(); i++)
    {
        if (check[i] == 0)
        {
            word.push_back(one_word[i]);
            check[i] = 1;
            dfs(dep + 1, i + 1, size, one_word);
            word.pop_back();
            check[i] = 0;
        }
    }
}
string solution(string number, int k)
{
    int size = number.size() - k;
    vector<char> one_word;
    for (int i = 0; i < number.size(); i++)
        one_word.push_back(number[i]);

    dfs(0, 0, size, one_word);

    return ans;
}

int main()
{
    string a = "1924";
    int b = 2;
    string ans = solution(a, b);
    cout << ans;
}