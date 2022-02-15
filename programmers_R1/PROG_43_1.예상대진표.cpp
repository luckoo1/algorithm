#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while (1)
    {
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
        answer += 1;
        if (a == b)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    int n = 8;
    int a = 3;
    int b = 7;
    int ans = solution(n, a, b);
    cout << ans << endl;
}