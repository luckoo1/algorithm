#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp (vector<int>a,vector<int> b)
{
    return a[0]<b[0];
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    sort(routes.begin(),routes.end(),cmp);
    for(int i=0;i<routes.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<routes[i][j]<<" ";
        }
        cout<<endl;
    }
    return answer;
}

int main()
{
    vector<vector<int>> a{ {-20, -15}, {-14, -5}, {-18, -13}, { -5, -3 }};
    cout<<"ANSWER: "<<solution(a)<<endl;
}