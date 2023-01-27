#include <iostream>
using namespace std;

//유클리드 호제법
int gcd(int a, int b) //최대공약수
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) //최소 공배수
{
    return a * b / gcd(a, b);
}
