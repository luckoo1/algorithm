#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    if(times.size()==1)
    {
        return n*times[0];
    }

    sort(times.begin(),times.end());
    long long start = 1;
    long long end = n * (long long)times[times.size()-1];

    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long cnt = 0;
        //mid시간동안 처리할수 있는 사람의수를 더한다.
        for(int i=0;i<times.size();i++)
        {
            cnt += mid/times[i];
        }
        if(cnt<n)
        {
            start = mid+1;
        }
        else
        {
            answer=mid;
            end = mid -1;
        }
    }

    return answer;
}
