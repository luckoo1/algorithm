/*
문제를 잘 파악하는 것에 대한 중요성을 한번더 생각해볼 수 있다.
sort한 다음에
i번째것과 i+1번째것만 비교해보면 된다
i+2, i+3째는 볼 필요도 없다.
*/
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    //////////////////////////////////////////////////////////////////
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////
    return true;
}

int main()
{
    vector<string> a = {"4321", "432"};
    vector<string> b = {"123", "124", "789"};
    vector<string> c = {"12", "34", "123", "1235", "567", "88"};
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    return 0;
}
