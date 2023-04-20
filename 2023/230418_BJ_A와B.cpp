//그리디
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("Input.txt", "r", stdin);
    string S,T;
    cin>>S>>T;
    while(1)
    {
        if(T.size()==S.size())
            break;

        if(T[T.size()-1]=='A')
            T.pop_back();
        else{
            T.pop_back();
            reverse(T.begin(),T.end());
        }
    }
    if(T==S)
        cout<<1;
    else
        cout<<0;
}