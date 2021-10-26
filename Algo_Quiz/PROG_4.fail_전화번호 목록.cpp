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

    int length = phone_book[0].size();

    vector<string> vec;
    vec.push_back(phone_book[0]);
    phone_book.erase(phone_book.begin());

    for (int i = 0; i < phone_book.size(); i++)
    {
        if (phone_book[i].size() != length)
            break;
        else
        {
            vec.push_back(phone_book[i]);
            phone_book.erase(phone_book.begin());
        }
    }

    if (phone_book.empty())
        return 1;

    for (int k = 0; k < vec.size(); k++)
    {
        for (int i = 0; i < phone_book.size(); i++)
        {
            string temp = "";

            for (int j = 0; j < length; j++)
            {
                if (vec[k][j] != phone_book[i][j])
                {
                    break;
                }

                if (j == length - 1)
                {
                    return false;
                }
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
    vector<string> c = {"12", "34", "123", "1235", "567", "88"};
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    return 0;
}
