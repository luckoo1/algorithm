#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    if (scoville.size() == 0)
    {
        return 0;
    }

    while (1)
    {

        if (scoville.size() == 1)
        {
            if (scoville[0] >= K)
                return answer;
            else
                return -1;
        }
        sort(scoville.begin(), scoville.end());

        if (scoville[0] >= K && scoville[scoville.size() - 1] >= K)
            break;

        int new_sco = scoville[0] + (scoville[1] * 2);
        scoville.erase(scoville.begin());

        scoville[0] = new_sco;
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