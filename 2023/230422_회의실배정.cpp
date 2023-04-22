//그리디
/*
고생했던 반례
3
4 4
4 4
1 4
bool sort_rule(vector<int> a,vector<int> b)
{
    if(a[1]<b[1])
        return true;
    return false;
}
이렇게 해서 처음에 계속 틀림
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define DEBUG (1)
bool sort_rule(vector<int> a,vector<int> b)
{
    if(a[1]<b[1])
        return true;
    else if(a[1]==b[1])
    {
        if(a[0]<b[0])
            return true;
        return false;
    }
    return false;
}
int main()
{
    //freopen("Input.txt", "r", stdin);
    int N;
    int temp;
    cin>>N;
    vector<vector<int>> vec(N,vector<int>(2,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>temp;
            vec[i][j] = temp;
        }
    }
    sort(vec.begin(),vec.end(),sort_rule);

    int end_time = vec[0][1];
    int ans = 1;
    for(int i=1;i<N;i++)
    {
        if(end_time>vec[i][0])
            continue;
        else
        {
            ans++;
            end_time = vec[i][1];
        }
    }
    cout<<ans;
}