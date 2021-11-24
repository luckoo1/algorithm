#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int ans;
int abs(int x)
{
    if (x < 0)
    {
        x = -x;
    }
    return x;
}

bool check_distance(vector<char> temp_ans, vector<string> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        char a = data[i][0];
        char b = data[i][2];
        char rule = data[i][3];
        int dist = data[i][4] - 48;
        int where_a;
        int where_b;
        for (int j = 0; j < temp_ans.size(); j++)
        {
            if (temp_ans[j] == a)
                where_a = j;
            else if (temp_ans[j] == b)
                where_b = j;
        }
        // for (auto n : temp_ans)
        // {
        //     cout << n << " ";
        // }
        // cout << endl;
        // cout << where_a << " " << where_b << endl;

        if (rule == '=')
        {
            if (abs(where_a - where_b) != dist + 1)
                return false;
        }
        else if (rule == '>')
        {
            if (abs(where_a - where_b) <= dist + 1) //여기에 +1안해서 틀림
                return false;
        }
        else if (rule == '<')
        {
            if (abs(where_a - where_b) >= dist + 1) //여기에 +1안해서 틀림
                return false;
        }
    }
    return true;
}

void dfs(int dep, vector<char> &people, vector<int> &check, vector<char> &temp_ans, vector<string> &data)
{
    if (dep == people.size())
    {
        if (check_distance(temp_ans, data) == true)
            ans += 1;
        return;
    }

    for (int i = 0; i < people.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            temp_ans.push_back(people[i]);
            dfs(dep + 1, people, check, temp_ans, data);
            check[i] = false;
            temp_ans.pop_back();
        }
    }
}

int solution(int n, vector<string> data)
{
    //vector<char> people{'N', 'A', 'F'};
    vector<char> people{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<int> check(people.size(), 0);
    vector<char> temp_ans;
    ans = 0;

    dfs(0, people, check, temp_ans, data);
    int answer = ans;
    return answer;
}

int main()
{
    int n = 2;
    vector<string> a{"N~F<2"};
    //vector<string> a{"N~F=0", "R~T>2"};
    vector<string> b{"M~C<2", "C~M>1"};

    int ans = solution(n, a);
    cout << ans;
}