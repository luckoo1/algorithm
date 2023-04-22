//그리디
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define DEBUG (1)

int main()
{
    //freopen("Input.txt", "r", stdin);
    string str;
    cin>>str;
    int cnt0=0;
    int cnt1=0;
    char now_char = str[0];
    for(int i=1;i<str.size();i++)
    {
        if(now_char==str[i])
            continue;
        else
        {
            if(now_char=='1')
                cnt1++;
            else if (now_char=='0')
                cnt0++;
            now_char = str[i];
        }
    }
    if(now_char=='0')
        cnt0++;
    else
        cnt1++;
    
    cout<<min(cnt0,cnt1);
}