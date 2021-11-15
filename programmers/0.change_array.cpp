#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = "[ [7], [ 3, 8 ], [ 8, 1, 0 ], [ 2, 7, 4, 4 ], [ 4, 5, 2, 6, 5 ] ]";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '[')
            a[i] = '{';
        if (a[i] == ']')
            a[i] = '}';
    }
    cout << a << endl;
}