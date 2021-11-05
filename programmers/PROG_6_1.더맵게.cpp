#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K)
{

    if (scoville.size() == 0)
    {
        return 0;
    }

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pri_q{scoville.begin(), scoville.end()};

    while (1)
    {
        if (pri_q.top() >= K)
        {
            break;
        }
        if (pri_q.size() == 1)
        {
            return -1;
        }

        int smallest = pri_q.top();
        pri_q.pop();

        int new_sco = smallest + (pri_q.top() * 2);
        pri_q.pop();

        pri_q.push(new_sco);

        answer += 1;
    }

    return answer;
}

int main()
{
    vector<int> a{1, 2, 3, 9, 10, 12};
    int b = 7;
    int ans = solution(a, b);
    cout << endl;
    cout << ans;
}