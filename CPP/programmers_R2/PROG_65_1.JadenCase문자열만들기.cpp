#include <string>
#include <vector>
#include <iostream>
using namespace std;

char upper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        ch = ch - ('a' - 'A');
    return ch;
}
char lower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + ('a' - 'A');
    return ch;
}
string solution(string s)
{
    s[0] = upper(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        if (s[i - 1] == ' ' && ch >= 'a' && ch <= 'z')
            s[i] = upper(s[i]);

        if (s[i - 1] != ' ' && ch >= 'A' && ch <= 'Z')
            s[i] = lower(s[i]);
    }
    return s;
}