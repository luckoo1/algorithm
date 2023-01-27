#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3};

    sort(v.begin(), v.end());

    do
    {
        for (auto n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}
