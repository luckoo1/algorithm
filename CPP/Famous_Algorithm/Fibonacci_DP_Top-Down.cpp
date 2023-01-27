/*Top-Down DP*/
#include <iostream>
using namespace std;
int MEMO[50]={0};

int Fibo(int n)
{
	
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(MEMO[n] != 0)
        return MEMO[n];

	MEMO[n] = Fibo(n - 1) + Fibo(n - 2);
	return MEMO[n];
}

int main()
{
	int n;
	cin>>n;
    int fibo = Fibo(n);
	cout<<fibo;
}