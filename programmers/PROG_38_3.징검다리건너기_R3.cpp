#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print(vector<int> v)
{
    cout << "PRINT" << endl;
    for (auto n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

bool check(vector<int> stones, int k, int ok_num)
{
    for (int i = 0; i < ok_num; i++)    //이거때문에 틀렸었음 -> 시간초과
    {
        int cnt = 0;
        for (int j = 0; j < stones.size(); j++)
        {
            if (stones[j] > 0)
            {
                stones[j] -= 1;
                cnt = 0;
            }
            else if (stones[j] == 0)
            {
                cnt += 1;
            }
            if (cnt >= k)
            {
                return false;
            }
        }
    }

    return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int start = 1;
    int end = *max_element(stones.begin(), stones.end());
    while (start <= end)
    {
        int ok_num = (start + end) / 2; // ok_num의 수대로 전부 건널수 있나?
        if (check(stones, k, ok_num) == true)
        {
            answer = ok_num;
            start = ok_num + 1;
        }
        else
        {
            end = ok_num - 1;
        }
    }
    return answer;
}

int main()
{
    solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3);
}