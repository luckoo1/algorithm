#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = [ " ABCFG ", " AC ", " CDE ", " ACDE ", " BCFG ", " ACDEH " ];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '[')
            a[i] = '{';
        if (a[i] == ']')
            a[i] = '}';
    }
    cout << a << endl;
}