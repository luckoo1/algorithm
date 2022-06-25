#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(int distance, vector<int> rocks, int n)
{
  int answer = 0;
  sort(rocks.begin(), rocks.end());

  int start = 0;
  int end = distance;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    
    int cnt = 0;
    int left = 0;
    for (int i = 0; i < rocks.size(); i++)
    {
      if (rocks[i] - left >= mid)
        left = rocks[i];
      else
        cnt++;
    }

    if (cnt > n)
    {
      end = mid - 1;
    }
    else
    {
      answer = mid;
      start = mid + 1;
    }
    //cout<<mid<<endl;
  }

  return answer;
}

int main()
{
    cout<<solution(25,	{2, 14, 11, 21, 17},2)<<endl;    
}