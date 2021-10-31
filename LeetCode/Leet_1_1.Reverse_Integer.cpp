#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;

        while (x != 0)
        {
            int pop = x % 10; //10으로 나눈 나머지니깐 젤 뒤에 값이 나온다.

            x /= 10; //10으로 나눈 몫이니깐 젤 뒤에 값이 사라진다

            /*
            int의 범위는 
            –2,147,483,648 ~ 2,147,483,647
            */

            //양수일때 범위 체크해보자
            //INT_MAX == 2,147,483,64
            if (rev > INT_MAX / 10)
                return 0;

            if (rev == INT_MAX / 10 && pop > 7) //INT_MAX가 2,147,483,64
                return 0;

            //음수일때 범위 체크
            if (rev < INT_MIN / 10) //INT_MIN == –2,147,483,64
                return 0;
            if (rev == INT_MIN / 10 && pop < -8)
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{
    Solution x;
    int a = 34566;

    cout << INT_MAX / 10;
    //int ans = x.reverse(a);
    //cout << ans << endl;
}