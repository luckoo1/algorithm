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
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size(); i++)
    {
        int length = phone_book[i].size();

        for (int j = i + 1; j < phone_book.size(); j++)
        {
            if (phone_book[i].size() == phone_book[j].size())
                continue;

            if (phone_book[i] == phone_book[j].substr(0, length)) //substr을 사용했다.
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
