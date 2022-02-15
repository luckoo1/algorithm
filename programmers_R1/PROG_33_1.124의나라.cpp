#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n)
{
    string ans = "";
    int num = n;

    while (num != 0)
    {
        if (num % 3 == 1)
        {
            ans += "1";
        }
        else if (num % 3 == 2)
        {
            ans += "2";
        }
        else if (num % 3 == 0)
        {
            ans += "4";
            num = (num / 3) - 1;
            continue;
        }
        num = num / 3;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int a = 5;
    string ans = solution(a);
    cout << ans;
}