#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int cnt = 0;
    while (1)
    {
        if (progresses.empty())
        {
            break;
        }
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }
        if (progresses[0] >= 100)
        {
            for (int i = 0; i < progresses.size(); i++)
            {
                cout << cnt << endl;
                if (progresses[i] >= 100)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            progresses.erase(progresses.begin(), progresses.begin() + cnt);
            speeds.erase(speeds.begin(), speeds.begin() + cnt);
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    return answer;
}

int main()
{
    vector<int> a1{93, 30, 55};
    vector<int> a2{1, 30, 5};
    vector<int> b1{95, 90, 99, 99, 80, 99};
    vector<int> b2{1, 1, 1, 1, 1};
    vector<int> answer = solution(a1, a2);
    for (auto n : answer)
    {
        cout << n << " ";
    }
}