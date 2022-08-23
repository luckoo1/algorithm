#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> vec;
int ans = 0;

void print_vec()
{
    cout<<"PRINT_VEC"<<" : ";
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void dfs(int n,int sum,int k)
{
    if(!vec.empty())
    {
        if(vec[0]<(n/2))
            return;
    }

    if(sum == n)
    {
        int temp_ans = (vec[0]) * (vec.size());
        if(temp_ans>ans)
            ans = temp_ans;
        return;
    }

    for(int i = k;i>=1;i--)
    {
        if(sum > n)
            continue;

        sum = sum + i;
        vec.push_back(i);

        dfs(n,sum, i-1);

        vec.pop_back();
        sum = sum-i;

    }
}

int solution(int n) {
    dfs(n,0,n);
    //cout<<ans;
    return ans;
}
/*
10
21

5
8
*/