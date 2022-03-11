#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    string answer = "";

    char biggest = 0;
    int idx = 0;

    for (int i = 0; i < number.size(); i++)
    {
        if (biggest < number[i])
        {
            biggest = number[i];
            idx = i;
        }

        if (i == k)
        {
            i = idx;
            k++;
            answer.push_back(biggest);
            biggest = 0;
        }
    }

    return answer;
}

int main()
{
    cout << solution("4177252841", 4) << endl;
    cout << endl;
    // cout << solution("4177252841", 4) << endl;
    // cout << endl;
    // cout << solution("1111", 2) << endl;
    // cout << endl;
}