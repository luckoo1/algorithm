#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int &num, vector<int> &stones, int &k)
{
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] <= num)
        {
            cnt++;
            if (cnt == k)
            {
                return false; //이 인원으로 건너면 다 못건넌다.
            }
        }
        else
        {
            cnt = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k)
{
    int start = 1;
    int end = *max_element(stones.begin(), stones.end());
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (binary_search(mid, stones, k))
        {
            start = mid +1; //다 건넘
        }
        else
        {
            end = mid -1; //다 못건넘
        }
    }
    return start;
}
int main()
{
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) << endl;
}