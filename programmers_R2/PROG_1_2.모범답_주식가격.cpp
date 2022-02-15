#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//1, 2, 3, 2, 3
//4, 3, 1, 1, 0
vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    stack<int> st;
    int size = prices.size();

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && prices[st.top()] > prices[i])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        answer[st.top()] = size - st.top() - 1;
        st.pop();
    }
    return answer;
}

int main()
{
    vector<int> a{1, 2, 3, 2, 3};
    vector<int> ans = solution(a);
    for (auto n : ans)
    {
        cout << n << " ";
    }
}