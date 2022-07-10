#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
    string s;
    cin>>s;
    map<int,int> hash_map;

    for(int i=0;i<s.size();i++)
    {
        int ascii = s[i];
        hash_map[ascii]++;
    }

    for(int i='a';i<='z';i++)
    {
        cout<<hash_map[i]<<" ";
    }

}