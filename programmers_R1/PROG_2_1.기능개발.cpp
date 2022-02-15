//https: //programmers.co.kr/learn/courses/30/lessons/42586

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int cnt = 0;
    vector<int> answer;

    while (!progresses.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] = progresses[i] + speeds[i];
        }

        while (progresses[0] >= 100)
        {
            cnt += 1;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            if (progresses.empty())
            {
                break;
            }
        }

        if (cnt != 0)
        {
            answer.push_back(cnt);
            cnt = 0;
        }
    }

    return answer;
}

int main()
{
    vector<int> prog1{93, 30, 55};
    vector<int> prog2{95, 90, 99, 99, 80, 99};

    vector<int> speed1{1, 30, 5};
    vector<int> speed2{1, 1, 1, 1, 1, 1};

    vector<int> ans = solution(prog1, speed1);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
}