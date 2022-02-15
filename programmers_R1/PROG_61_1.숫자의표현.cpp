#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(int num, int ans)
{
    int i = num + 1;
    while (1)
    {
        num = num + i;
        if (num >= ans)
        {
            if (num == ans)
                return true;
            else
                return false;
        }
        i += 1;
    }
}
int solution(int n)
{
    int ans = 0;
    for (int i = 1; i < n / 2; i++)
    {
        if (check(i, n) == true)
        {
            ans += 1;
        }
    }
    return ans + 1;
}