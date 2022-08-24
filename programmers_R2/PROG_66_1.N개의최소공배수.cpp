#include <iostream>
#include <vector>
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

int solution(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int lcm_num = lcm(arr[i], arr[i + 1]);
        arr[i + 1] = lcm_num;
    }
    return arr[arr.size() - 1];
}