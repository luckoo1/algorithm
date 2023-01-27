#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

queue<int> q;

int solution(vector<int> query, int n, int k, int x) {
    int answer = 0;

    for(int i=0;i<query.size();i++)
    {
        q.push(query[i]);
    }

    int num = q.front();
    q.pop();

    while(!q.empty()||num!=0)  //큐가 비고 num이 0이면 stop
    {
        int flag = 0;
        for(int i=0;i<k;i++)
        {
            num = num-x;
            if(num<=0)
            {
                if(!q.empty())
                {
                    num = q.front();
                    q.pop();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag ==1)
        {
            break;
        }
        answer += n+1;

    }

    return answer;
}

int main()
{
    cout<<solution({1,3,2},4,1,1);
}
#if 0 
        for(int i=0;i<k;i++)
        {
            num = num-x;
            cout<<num<<","<<answer<<endl;
            if(num<=0)
            {
                if(!q.empty())
                {
                    num = q.front();
                    q.pop();
…        {
        answer+=n;
        }
#endif
