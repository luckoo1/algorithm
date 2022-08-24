#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check[10001];
string temp_str = "";
string temp_ans = "a";
void dfs(int dep, string now_place, vector<vector<string>> tickets)
{
    if (dep == tickets.size())
    {
        if (temp_ans > temp_str)
        {
            temp_ans = temp_str;
        }
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (check[i] == false && tickets[i][0] == now_place)
        {
            temp_str += tickets[i][1];
            check[i] = true;
            dfs(dep + 1, tickets[i][1], tickets);
            temp_str.pop_back();
            temp_str.pop_back();
            temp_str.pop_back();
            check[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    answer.push_back("ICN");
    dfs(0, "ICN", tickets);
    for (int i = 0; i < temp_ans.size(); i+=3)
    {
        answer.push_back(temp_ans.substr(i,3));
    }
    return answer;
}

int main()
{
    // vector<string> answer = solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
    vector<string> answer = solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});
    for (auto n : answer)
    {
        cout << n << " ";
    }
    cout << endl;
}