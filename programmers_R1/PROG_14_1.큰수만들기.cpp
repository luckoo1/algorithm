#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    for (int i = 0; i < k; i++)
    {
        bool flag = false;
        for (int j = 0; j < number.size() - 1; j++)
        {
            if (number[j] < number[j + 1])
            {
                number.erase(number.begin() + j);
                flag = true;
                break;
            }
        }
        if(flag==false)
        {
            number.pop_back();
        }
    }
    return number;
}

int main()
{
    cout << solution("1924", 2) << endl;
    cout << endl;
    cout << solution("4177252841", 4) << endl;
    cout << endl;
    cout << solution("1111", 2) << endl;
    cout << endl;
}