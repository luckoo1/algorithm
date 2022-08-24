#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> operations)
{
    priority_queue<int> priority_q;
    vector<int>answer;

    for (int i = 0; i < operations.size();i++)
    {
        if (operations[i][0]=='I')
        {
            string temp_str = "";
            for (int j = 2; j < operations[i].size();j++)
            {
                temp_str.push_back(operations[i][j]);
            }
            priority_q.push(stoi(temp_str));
            continue;
        }
        else if(priority_q.size()==1)
        {
            priority_q.pop();
            continue;
        }
        else if (operations[i] == "D 1" && !priority_q.empty())
        {
            priority_q.pop();
        }
        else if (operations[i] == "D -1" && !priority_q.empty())
        {
            while (priority_q.size() != 1)
            {
                answer.push_back(priority_q.top());
                priority_q.pop();
            }
            priority_q.pop();
            for (int i = 0; i < answer.size();i++)
            {
                priority_q.push(answer[i]);
            }
            answer.clear();
        }
    }

    if (priority_q.empty())
    {
        return {0,0};
    }
    else
    {
        answer.push_back(priority_q.top());
        while(priority_q.size()!=1)
        {
            priority_q.pop();
        }
        
        answer.push_back(priority_q.top());
        return answer;
    }
}

int main()
{

    vector<string> a{"I 16", "D 1"};
    vector<string> b{"I 7", "I 5", "I -5", "D -1"};

    vector<int> ans = solution(a);
    for(auto n: ans)
    {
        cout << n << " ";
    }
    cout << endl;

    vector<int> ans1 = solution(b);
    for(auto n: ans1)
    {
        cout << n << " ";
    }
    cout << endl;
}