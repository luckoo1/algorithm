#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check_binary(vector<int> rocks, int n, int mid)
{
    int cnt = 0;
    for (int i = 0; i < rocks.size()-1; i++)
    {
        if(rocks[i+1]-rocks[i]>= mid)
    }
}
int solution(int distance, vector<int> rocks, int n)
{
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    int start = 0;
    int end = distance;

    while (start <= end)
    {
        int mid = (start + end) / 2;
    }


    return answer;
}

int main()
{
    cout<<solution(25,	{2, 14, 11, 21, 17},2)<<endl;    
}