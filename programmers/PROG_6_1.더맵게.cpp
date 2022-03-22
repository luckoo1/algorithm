#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> priority_q)
{
    while (!priority_q.empty())
    {
        cout << priority_q.top() << " ";
        priority_q.pop();
    }
    cout << endl;
    return;
}

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> priority_q(scoville.begin(), scoville.end());
    //위와같이 초기화하는걸 추천
    //나는 아래와 같이 했다.
    /*
    priority_queue<int, vector<int>, greater<int>> priority_q;
    for (int i = 0; i < scoville.size(); i++)
    {
        priority_q.push(scoville[i]);
    }
    */

    while (1)
    {

        if (priority_q.size() == 1)
        {
            if (priority_q.top() < K)
            {
                return -1;
            }
        }

        if (priority_q.top() >= K)
        {
            break;
        }

        answer += 1;
        int min = priority_q.top();
        priority_q.pop();
        int next_min = priority_q.top();
        priority_q.pop();

        int mix_scoville = min + (next_min * 2);
        priority_q.push(mix_scoville);
    }
    return answer;
}

int main()
{
    vector<int> a{1, 2, 3, 9, 10, 12};
    int b = 7;
    int ans = solution(a, b);
    cout << ans << endl;
}
/*벡터사용해서 효율성에서 다 틀린 풀이*/
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    while (1)
    {

        sort(scoville.begin(), scoville.end());
        if (scoville.size() == 1)
        {
            if (scoville[0] < K)
            {
                return -1;
            }
        }

        if (scoville[0] >= K)
        {
            break;
        }

        answer += 1;
        int mix_scoville = scoville[0] + (scoville[1] * 2);
        scoville.erase(scoville.begin(), scoville.begin() + 2);
        scoville.push_back(mix_scoville);
    }
    return answer;
}
*/