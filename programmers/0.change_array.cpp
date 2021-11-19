#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = "[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '[')
            a[i] = '{';
        if (a[i] == ']')
            a[i] = '}';
    }
    cout << a << endl;
}