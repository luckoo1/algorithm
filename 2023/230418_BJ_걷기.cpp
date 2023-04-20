//그리디
#include <iostream>
#include <algorithm>
using namespace std;

int abs(int num)
{
    if(num<0)
        return -num;
    return num;
}

int main()
{
    long long x,y,w,s;
    cin>>x>>y>>w>>s; //w:한블록 ,s:대각
    
    long long go_w_time = min(2*w,s);
    long long go_w_many = min(x,y);
    long long  min_w_time = (go_w_many*go_w_time);

    long long go_s_many = abs(x-y);
    long long two_s_min = min(2*w,2*s);
    long long two_s_many = go_s_many/2;
    long long one_s_many = go_s_many%2;

    long long min_s_time = (two_s_many*two_s_min)+(one_s_many*w);
    long long num = min_w_time+min_s_time;
    cout<<num;
    
}