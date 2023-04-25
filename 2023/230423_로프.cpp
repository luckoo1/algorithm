//그리디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_rule(int a,int b)
{
    if(a>b)
        return true;
    return false;
}
int main()
{
    //freopen("Input.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> vec;
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);

    }
    sort(vec.begin(),vec.end(),sort_rule);
    int ans = vec[0];
    for(int i=1;i<N;i++)
    {
        int temp_ans = vec[i]*(i+1);
        if(ans<temp_ans)
            ans = temp_ans;
    }
    cout<<ans;
}