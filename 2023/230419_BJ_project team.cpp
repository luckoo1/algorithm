//그리디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    //freopen("Input.txt", "r", stdin);
    int N;
    int num;
    cin>>N;
    vector<int> vec;
    for(int i=0;i<2*N;i++)
    {
        cin>>num;
        vec.push_back(num);
    }

    sort(vec.begin(),vec.end());
    int a,b;
    vector<int> sum_team;
    for(int i=0;i<N;i++)
    {
        a=i;
        b=(2*N)-1-i;
        num = vec[b]+vec[a];
        sum_team.push_back(num);
    }
    int ans = *min_element(sum_team.begin(),sum_team.end());
    cout<<ans;
}