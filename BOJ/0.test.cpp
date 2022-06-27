#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DATA
{
    int r;
    int c;
    DATA(int r,int c)
    {
        this->r = r;
        this->c =c;
    }

};
bool sort_rule(vector<int> a,vector<int> b)
{
    return a.size()>b.size();
}

int main()
{
    vector<vector<int>> vec;
    vec.push_back({1,2,3});
    vec.push_back({1,2});
    vec.push_back({1,2,3,4});
    sort(vec.begin(),vec.end(),sort_rule);

    for(auto n:vec)
    {
        for(int i=0;i<n.size();i++)
        {
            cout<<n[i]<<" ";
        }
        cout<<endl;
    }

}