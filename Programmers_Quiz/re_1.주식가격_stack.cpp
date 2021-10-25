#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices)
{
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st;

    for (int t = 0; t < size; t++)
    {

        //stack이 비어있지않고
        //감소하는 주식이 발생했다면
        while (!st.empty() && prices[st.top()] > prices[t])
        {
            //가격이 떨어졌으므로 "t" - 스택 마지막값" 대입
            //t(현재 주식의 감소 시점) - st.top()(주식이 처음 들어간 시점)
            //t라는 시간에서 st.top()이라는 시간을 빼 준다는 의미가 됩니다.

            answer[st.top()] = t - st.top();

            //값제거
            st.pop();
            //반복문인 이유: 가격이 같은값이 유지되었을경우
            //현재값보다 계속작으므로 1개차이씩 넣어주기 위해서다.
        }
        //현재 인덱스를 스택에 넣기
        st.push(t);
    }

    //st  "0 1 3 4"
    //즉 st에는 증가했을때 시점만 나온다.

    //answer "0 0 1 0 0"

    // while (!st.empty())
    // {
    //     printf("%d ", st.top());
    //     st.pop();
    // }

    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d ", answer[i]);
    }
    printf("\n");

    while (!st.empty())
    {
        //위에서 특정위치에 이미값을 넣었으므로 push_back이나 insert로하면 안된다.
        //뒤에서부터 넣어야하므로 size-1 에서 top값을 빼준다.
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}

int main()
{
    vector<int> v{3, 5, 5, 4, 1};
    vector<int> ans = solution(v);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
}