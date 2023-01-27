/*Bottom-Up DP*/
#include <iostream>
using namespace std;
int MEMO[50]={0};
int main()
{
	int n;
	cin>>n;
	MEMO[1]=1;
	MEMO[2]=1;
	for(int i=3;i<=n;i++)
	{
		MEMO[i]=MEMO[i-1]+MEMO[i-2];
	}
	cout<<MEMO[n];
	
}