#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(int N, int number)
{
    int ans = -1;
    vector<unordered_set<int>> ser(10);

    int num = N;

    for (int i = 1; i <= 9; i++)
    {
        ser[i].insert(num);
        num = (num * 10) + N;
    }

    for (int i = 1; i <= 9; i++)
    {
        //cout << "START : " << i << endl;
        for (int j = 1; j < i; j++)
        {
           //cout << j << "," << i - j << endl;
            for (auto m : ser[j])
            {
                for (auto n : ser[i - j])
                {
                    ser[i].insert(m + n);
                    ser[i].insert(m - n);
                    ser[i].insert(m * n);
                    if (n != 0)
                        ser[i].insert(m / n);
                }
            }
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        //cout << "START : " << i << endl;
        for (auto m : ser[i])
        {
            //cout<<m<<" ";
            if (m == number)
            {
                ans = i;
                return ans;
            }
        }
        //cout<<endl;
    }

    return ans;
}