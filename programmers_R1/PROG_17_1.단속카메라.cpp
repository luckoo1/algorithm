#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp (vector<int>a,vector<int> b)
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    sort(routes.begin(),routes.end(),cmp);

    int cam = -30001;
    for(int i=0;i<routes.size();i++)
    {
        if(routes[i][0]>cam)
        {
            cam = routes[i][1];
            answer+=1;
        }
    }

    return answer;
}


int main()
{
    vector<vector<int>> a{ {-20, -15}, {-14, -5}, {-18, -13}, { -5, -3 }};
    cout<<"ANSWER: "<<solution(a)<<endl;
}