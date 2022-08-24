#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    answer = number.substr(k);
    cout << "answer : " << answer << endl;
    cout << "number : " << number << endl;
    cout << endl;
    cout << "answer : " << answer << endl;
    cout << "sub_number : " << number.substr(0, 4) << endl;
    cout << endl;
    for (int i = k - 1; i >= 0; i--) //3 2 1 0
    {
        int j = 0;
        do
        {
            if (number[i] >= answer[j])
            {
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
                cout << "answer : " << answer << endl;
                cout << "sub_number : " << number.substr(0, 4) << endl;
            }
            else
            {
                break;
            }
        } while (1);
    }
    return answer;
}

int main()
{
    string a = "4177252841";
    int b = 4;
    string ans = solution(a, b);
    cout << "answer : " << ans;
}