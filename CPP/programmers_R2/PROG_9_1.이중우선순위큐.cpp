#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations)
{
    priority_queue<int> pri_q;
    queue<int> q;
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            operations[i].erase(operations[i].begin(), operations[i].begin() + 1);
            int a = stoi(operations[i]);
            pri_q.push(a);
            continue;
        }

        if (pri_q.size() == 1)
        {
            pri_q.pop();
            continue;
        }

        if (operations[i] == "D 1" && !pri_q.empty())
        {
            pri_q.pop();
        }

        if (operations[i] == "D -1" && !pri_q.empty())
        {
            while (pri_q.size() != 1)
            {
                q.push(pri_q.top());
                pri_q.pop();
            }
            pri_q.pop();

            while (!q.empty())
            {
                pri_q.push(q.front());
                q.pop();
            }
        }
    }

    if (pri_q.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }

    answer.push_back(pri_q.top());
    pri_q.pop();

    while (!pri_q.empty())
    {
        if (pri_q.size() == 1)
        {
            answer.push_back(pri_q.top());
            pri_q.pop();
            break;
        }
        pri_q.pop();
    }

    return answer;
}

int main()
{
    vector<string> a1{"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<string> b1{"I 7", "I 5", "I -5", "D -1"};

    vector<int> ans = solution(a1);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}