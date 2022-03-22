#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0, minTime = 1, maxTime, avgTime, human = 0;
    //최대값은 최대시간 * 인원수
    maxTime = *max_element(times.begin(), times.end()) * (long long)n;
    cout << maxTime << endl;

    //최소시간이 최대시간과 같거나 적을때까지 반복
    while (minTime <= maxTime)
    {
        //평균시간 구하기
        avgTime = ((maxTime + minTime) / 2);

        //현재 시간으로 돌릴수 잇는 최대인원 구하기
        for (int i = 0; i < times.size(); i++)
        {
            // 각 시간별 mid 시간 동안 처리할 수 있는 사람들 수를 더해준다.
            human += avgTime / times[i];
        }
        //최대인원이 총인원보다 크거나 같다면
        if (n <= human)
        {
            //현재 시간을 정답에 저장(나중에 안나오면 리턴해야 해서
            answer = avgTime;
            //최대시간 갱신
            maxTime = avgTime - 1;
        }
        //총인원보다 적다면 현재보다 시간이커야하므로 최소시간 갱신
        else
            minTime = avgTime + 1;
        //사람수 초기화
        human = 0;
    }
    return answer;
}

int main()
{
    int a = 6;
    vector<int> b = {7, 10};
    long long ans = solution(a, b);
    cout << ans;
}
