#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    if (s.size() % 2 != 0) //모서리 케이스
        return 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char temp = s[0];
        s.erase(s.begin());
        s.push_back(temp);
        stack<char> st;
        bool flag = false;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '[' || s[j] == '(' || s[j] == '{')
                st.push(s[j]);
            else
            {
                if (st.empty())
                {
                    flag = true;
                    break;
                }
                else if (s[j] == ']')
                {
                    if (st.top() != '[')
                    {
                        flag = true;
                        break;
                    }
                    st.pop();
                }
                else if (s[j] == ')')
                {
                    if (st.top() != '(')
                    {
                        flag = true;
                        break;
                    }
                    st.pop();
                }
                else if (s[j] == '}')
                {
                    if (st.top() != '{')
                    {
                        flag = true;
                        break;
                    }
                    st.pop();
                }
            }
        }

        if (flag == false)
            ans += 1;
    }

    return ans;
}

int main()
{
    string a = "[](){}";
    int ans = solution(a);
    cout << "ANS : " << ans << endl;
}