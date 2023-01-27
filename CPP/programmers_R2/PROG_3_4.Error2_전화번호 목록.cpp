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

            for (int k = 0; k < length; k++)
            {
                if (phone_book[i][k] != phone_book[j][k])
                {
                    break;
                }
                if (k == length - 1) //1.이걸 빼먹어서 오류가 떴다
                    return false;
            }

            //2.
            //처음에 이렇게 썻는데 그러면 글자를 전부 비교 안하고 바로위에 for문에서 나오자마자 return 하잖아
            //return false;
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
