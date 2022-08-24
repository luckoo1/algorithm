#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    string answer = "";

    int biggest = 0;
    int idx = 0;

    for (int i = 0; i < number.length(); ++i)
    {
        //cout << i << " ";
        if (biggest < number[i])
        {
            biggest = number[i];
            idx = i;
        }

        if (i == k)
        {
            i = idx;
            ++k;
            answer.push_back(biggest);
            biggest = 0;
            cout << "i : " << i << endl;
            cout << "k : " << k << endl;
        }
    }

    return answer;
}

int main()
{
    string a = "4177252841";
    int b = 4;
    string ans = solution(a, b);
    cout << ans;
}