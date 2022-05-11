/*int a = char - 48;  //char를 int로 만드는법*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check[8];
int max_num;
string temp_ans;
int answer;

int abs(int a, int b)
{
    int dst = a - b;
    if (dst < 0)
    {
        return -dst;
    }
    return dst;
}

bool check_dist(string str)
{
    int a;
    int b;
    char how = str[3];
    for (int i = 0; i < max_num; i++)
    {
        if (temp_ans[i] == str[0])
        {
            a = i;
        }
        if (temp_ans[i] == str[2])
        {
            b = i;
        }
    }
    int between = abs(a, b) - 1;

    if (how == '=')
    {
        if(between == str[4]-'0')
        {
            return true;
        }
        return false;
    }
    else if (how == '<')
    {
        if(between < str[4]-'0')
        {
            return true;
        }
        return false;
    }
    else if (how == '>')
    {
        if(between > str[4]-'0')
        {
            return true;
        }
        return false;
    }
}
void dfs(int dep, vector<char> &people, vector<string> &data)
{
    if (dep == max_num)
    {
        for(int i=0;i<data.size();i++)
        {
            if(check_dist(data[i])==false)
            {
                return;
            }
        }
        answer++;
        return;
    }
    for (int i = 0; i < max_num; i++)
    {
        if (check[i] == false)
        {
            temp_ans.push_back(people[i]);
            check[i] = true;
            dfs(dep + 1, people, data);
            temp_ans.pop_back();
            check[i] = false;
        }
    }
}

int solution(int n, vector<string> data)
{
    answer=0;
    temp_ans = "";
    vector<char> people{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    max_num = people.size();

    for (int i = 0; i < 8; i++)
    {
        check[i] = false;
    }
    dfs(0, people, data);

    return answer;
}

int main()
{
    temp_ans = "AMCJRTNF";
    max_num = 8;
    cout<<check_dist("N~F=0")<<endl;
    //cout << solution(2, {"N~F=0"}) << endl;

    //cout << solution(2, {"N~F=0", "R~T>2"}) << endl;
    // cout << solution(2, {"M~C<2", "C~M>1"}) << endl;
}