#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = "[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '[')
            a[i] = '{';
        if (a[i] == ']')
            a[i] = '}';
    }
    cout << a << endl;
}