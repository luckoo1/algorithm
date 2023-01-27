#include <iostream>
#include <cmath>
using namespace std;

int number = 120; // 구하고자 하는 소수의 범위
int primeNum[121];

void primeNumberSieve()
{
    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // 소수 출력
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
            printf("%d\n", primeNum[i]);
    }
}
int main()
{
    primeNumberSieve();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int max_num = 100;
    bool check[100];

    //소수가 아닌걸 true처리하자
    check[0] = true;
    check[1] = true;

    for (int i = 2; i <= sqrt(100); i++)
    {
        if (check[i] == true)
            continue;
        for (int j = i * i; j <= 100; j += i)
            check[j] = true;
    }

    for (int i = 0; i < 100; i++)
    {
        if (check[i] == false)
            cout << i << endl;
    }
}