#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string p)
{
    stack<char> st;
    vector<int> check(p.size(), 0);
    int cnt = 0;

    for (int i = 0; i < p.size(); i++)
    {

        if (p[i] == '(')
        {
            if (cnt == 0)
            {
                st.push('(');
            }
            else
            {
                cnt -= 1;
                check[i] = 1;
            }
        }
        else if (p[i] == ')')
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
            {
                cnt += 1;
                check[i] = 1;
            }
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        if (check[i] == 1)
        {
            if (p[i] == '(')
            {
                p[i] = ')';
            }
            else
            {
                p[i] = '(';
            }
        }
    }

    return p;
}

int main()
{
    string a = "(()())()";
    string b = ")(";
    string c = "()))((()";
    //         "()(())()"
    string ans = solution(c);
    cout << ans;
}