#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10002];
int main()
{
    //freopen("Input.txt", "r", stdin);
    int n,cost,c;
    vector<int> coin_vec;
    cin>>n>>cost;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        coin_vec.push_back(c);
    }
    dp[0]=1;
    for(int i=0;i<coin_vec.size();i++)
    {
        for(int j=coin_vec[i];j<=cost;j++)
        {
            dp[j] +=dp[j-coin_vec[i]];
        }
    }
    cout<<dp[cost];
}