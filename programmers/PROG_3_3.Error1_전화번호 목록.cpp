//깡코딩 : 시간초과
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    //////////////////////////////////////////////////////////////////

    //문제를 재대로 이해 못했다.
    //전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
    //sort가 필요한 이유이다.
    //그러나 이것도 맞는건 아니다.
    sort(phone_book.begin(), phone_book.end());

    int length = phone_book[0].size();

    for (int i = 1; i < phone_book.size(); i++)
    {
        if (phone_book[i].size() < length)
        {
            continue;
        }

        string temp = "";
        for (int j = 0; j < length; j++)
        {
            if (phone_book[0][j] != phone_book[i][j])
            {
                break;
            }

            if (j == length - 1)
            {
                return false;
            }
        }
    }

    //////////////////////////////////////////////////////////////////
    return true;
}

int main()
{
    vector<string> a = {"4321", "432"};
    vector<string> b = {"123", "124", "789"};
    vector<string> c = {"12", "123", "1235", "567", "88"};
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    return 0;
}
