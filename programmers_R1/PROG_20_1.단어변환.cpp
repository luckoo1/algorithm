#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 9999;
bool check[51];

bool check_diff(string a, string b)
{
    int n = a.size();
    int cnt_diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cnt_diff += 1;
        }
        if (cnt_diff >= 2)
        {
            return false;
        }
    }
    if (cnt_diff == 1)
    {
        return true;
    }
}

void dfs(int temp_ans, string now_string, const string &target, vector<string> words)
{
    if (now_string == target)
    {
        if (answer > temp_ans)
        {
            answer = temp_ans;
        }
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (check[i] == false && check_diff(now_string, words[i]))
        {
            check[i] = true;
            temp_ans += 1;
            dfs(temp_ans, words[i], target, words);
            temp_ans -= 1;
            check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    dfs(0, begin, target,words);
    if(answer==9999)
    {
        return 0;
    }
    return answer;
}

int main()
{
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    for(int i=0;i<8;i++)
    {
        check[i]=false;
    }
    answer=9999;
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << endl;
}