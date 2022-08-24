#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count_one(int n)
{
    int one_cnt = 0;
    string str_binary = "";

    while (1)
    {
        str_binary += to_string(n % 2);
        if (n % 2 == 1)
            one_cnt += 1;
        n = n / 2;
        if (n == 1)
        {
            str_binary += to_string(n);
            break;
        }
    }
    return one_cnt;
}

int solution(int n)
{
    int cnt_one = count_one(n);
    while (1)
    {
        n += 1;
        if (cnt_one == count_one(n))
            return n;
    }
}

int main()
{
    cout << solution(78) << endl;
    cout << solution(15) << endl;
}