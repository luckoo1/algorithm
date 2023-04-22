//그리디
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	//freopen("Input.txt", "r", stdin);
	int N,day;
	cin>>N;
	for(int k=0;k<N;k++)
	{
		cin>>day;
		vector<int> cost;
		for(int i=0;i<day;i++)
		{
			int temp;
			cin>>temp;
			cost.push_back(temp);
		}
		long long ans = 0;
		long long now_cost = cost[cost.size()-1];
		for(int i=cost.size()-2;i>=0;i--)
		{
			if(cost[i] <= now_cost)
			{
				ans += now_cost - cost[i];
			}
			else
			{
				now_cost = cost[i];
			}
		}
		cout<<ans<<endl;
	}
}