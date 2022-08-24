#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void print_muliset(multiset<int> m_set)
{
    for (auto iter = m_set.begin(); iter != m_set.end();iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<int> solution(vector<string> operations)
{
    multiset<int> m_set;
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            string temp_str = "";
            for (int j = 2; j < operations[i].size(); j++)
            {
                temp_str.push_back(operations[i][j]);
            }
            m_set.insert(stoi(temp_str));
            continue;
        }
        else if (m_set.size() == 1)
        {
            m_set.clear();
            continue;
        }
        else if (operations[i] == "D 1" && !m_set.empty())
        {
            m_set.erase(--m_set.end());
        }
        else if (operations[i] == "D -1" && !m_set.empty())
        {
            m_set.erase(m_set.begin());
        }
    }
    
    if (m_set.empty())
    {
        return {0, 0};
    }
    else
    {
        auto iter = --m_set.end();
        answer.push_back(*iter);
        iter = m_set.begin();
        answer.push_back(*iter);
        return answer;
    }
}

int main()
{

    vector<string> a{"I 16", "D 1"};
    vector<string> b{"I 7", "I 5", "I -5", "D -1"};

    vector<int> ans = solution(a);
    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;

    vector<int> ans1 = solution(b);
    for (auto n : ans1)
    {
        cout << n << " ";
    }
    cout << endl;
}