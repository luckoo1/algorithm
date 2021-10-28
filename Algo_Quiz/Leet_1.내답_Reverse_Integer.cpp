#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int x = -48390;

    if (x == 0 || x > INT_MAX || x < INT_MIN) //0 check or int범위 체크
    {
        return 0;
    }

    bool minus_flag = false; //음수여부 체크
    if (x < 0)
    {
        minus_flag = true;
    }

    string str = to_string(x); //int를 string으로

    if (minus_flag == true) //음수면 일단 -를 빼자
    {
        str.erase(str.begin());
    }

    ::reverse(str.begin(), str.end()); //reverse하고

    while (1) //0부터 시작하면 삭제해주자!
    {
        if (str[0] == '0')
        {
            str.erase(str.begin());
        }
        else
            break;
    }

    long long num = stoll(str); //정수로 변환하는데 long long으로 해줬다.

    if (num == 0 || num > INT_MAX || num < INT_MIN) //0임을 check or int범위 체크
    {
        return 0;
    }

    if (minus_flag == true) //기존에 음수였는지 check
    {
        long long temp_num = num;   //★int범위 넘어서 long long씀
        num = num - (2 * temp_num); //음수였으면 2번 빼줘서 minus만든다.
    }

    int ans = num;

    ///////////////////////////////////////////////////////////
    return ans;
}