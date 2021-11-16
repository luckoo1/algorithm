#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = "[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '[')
            a[i] = '{';
        if (a[i] == ']')
            a[i] = '}';
    }
    cout << a << endl;
}