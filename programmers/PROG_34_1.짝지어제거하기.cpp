#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    s.erase(s.begin());

    for (int i = 0; i < s.size(); i++)
    {
        char word = s[i];
        if (st.empty())
        {
            st.push(word);
            continue;
        }
        if (word == st.top())
            st.pop();
        else
            st.push(word);
    }

    int ans = -1;

    if (st.size() == 0)
        ans = 1;
    else
        ans = 0;

    return ans;
}

int main()
{
    string a = "cdcd";
    int ans = solution(a);
    cout << ans;
}