#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check[10001]{false};
string temp_ans = "~";

void dfs(int dep, string course, string start, vector<vector<string>> tickets)
{
    if (dep == tickets.size())
    {
        if (course < temp_ans)
        {
            temp_ans = course;
        }
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (check[i] == false && tickets[i][0] == start)
        {
            check[i] = true;
            course = course + tickets[i][1];
            dfs(dep + 1, course, tickets[i][1], tickets);
            check[i] = false;
            course.erase(course.end() - 3, course.end());
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    dfs(0, "ICN", "ICN", tickets);
    int size = temp_ans.size();
    string one_course = "";
    vector<string> answer;
    /*
    이건 내답이었다.
    for (int i = 0; i < size; i++)
    {
        one_course = one_course + temp_ans[i];
        if (i % 3 == 2)
        {
            answer.push_back(one_course);
            one_course = "";
        }
    }
    */

    //이게 더 좋은 표현같다.
    for (int i = 0; i < temp_ans.size(); i += 3)
    {
        answer.push_back(temp_ans.substr(i, 3));
    }
    return answer;
}

int main()
{
    vector<vector<string>> a{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    vector<vector<string>> b{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    vector<string> ans = solution(b);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}