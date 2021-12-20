/*
깡코딩 구현
처음에 ★부분 없어서 테케부분 틀림뜸
★부분이 필요한 이유는 저게 없으면 맨 앞부분에서 A,B,C,D,E,F가 오는걸 고려못한다
예를들어 "A11134"가 나오는걸 고려못하는 거다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string make_notation(int num, int n)
{
    string notation_str = "";
    while (1)
    {
        int notation_num = num % n;
        num = num / n;

        if (notation_num >= 10)
        {
            if (notation_num == 10)
                notation_str += "A";
            else if (notation_num == 11)
                notation_str += "B";
            else if (notation_num == 12)
                notation_str += "C";
            else if (notation_num == 13)
                notation_str += "D";
            else if (notation_num == 14)
                notation_str += "E";
            else if (notation_num == 15)
                notation_str += "F";
        }
        else
            notation_str += to_string(notation_num);

        if (num < n)
        {
            if (num != 0)
            {
                //★
                if (num >= 10)
                {
                    if (num == 10)
                        notation_str += "A";
                    else if (num == 11)
                        notation_str += "B";
                    else if (num == 12)
                        notation_str += "C";
                    else if (num == 13)
                        notation_str += "D";
                    else if (num == 14)
                        notation_str += "E";
                    else if (num == 15)
                        notation_str += "F";
                }
                else
                {
                    notation_str += to_string(num);
                }
                //★
            }
            break;
        }
    }
    reverse(notation_str.begin(), notation_str.end());
    return notation_str;
}
string solution(int n, int t, int m, int p)
{
    string all_notation_str = "";
    int i = 0;
    while (1)
    {
        all_notation_str += make_notation(i, n);

        if (all_notation_str.size() >= t * m)
            break;
        i += 1;
    }

    string ans = "";
    for (int i = 0; i < all_notation_str.size(); i++)
    {
        if (i % m == p - 1)
        {
            ans += all_notation_str[i];
        }
        if (ans.size() == t)
            break;
    }
    return ans;
}

int main()
{
    int n1 = 2;
    int t1 = 4;
    int m1 = 2;
    int p1 = 1;
    cout << solution(n1, t1, m1, p1) << endl;
    int n2 = 16;
    int t2 = 16;
    int m2 = 2;
    int p2 = 1;
    cout << solution(n2, t2, m2, p2) << endl;
}