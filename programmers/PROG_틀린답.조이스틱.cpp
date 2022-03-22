#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count_move_char(char ch)
{
    int diff1 = ch - 'A';
    int diff2 = 26 - (ch - 'A');

    if (diff1 < diff2)
        return diff1;
    else
        return diff2;
}

int solution(string name)
{
    int answer = 0;
    vector<bool> check(name.size(), false);

    for (int i = 0; i < name.size(); i++)
    {
        answer += count_move_char(name[i]);
        if (name[i] == 'A')
            check[i] = true;
    }
    check[0] = true;

    int index = 0;
    int move = 0;

    while (1)
    {
        int cnt_true = 0;
        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] == false)
                continue;
            cnt_true += 1;
        }

        if (cnt_true == name.size())
        {
            break;
        }

        move = 0;
        for (int i = 1; i < name.size(); i++)
        {
            move += 1;
            int right_move = (index + i) % name.size();
            int left_move = ((index - i) + name.size()) % name.size();
            /*
            right_move부터 하냐
            left_move부터 하냐에 따라 답이 달라진다..
            ZZAAAZZ
            right부터하면 8
            left부터하면 9

            */
            if (check[right_move] == false)
            {
                index = right_move;
                break;
            }
            if (check[left_move] == false)
            {
                index = left_move;
                break;
            }
        }
        answer += move;
        check[index] = true;
    }

    return answer;
}
int main()
{
    // int index = 3;
    // int move = 0;
    // for (int i = 1; i < 10; i++)
    // {
    //     move += 1;
    //     int right_move = (index + i) % 10;
    //     int left_move = ((index - i) + 10) % 10;
    //     cout << right_move << "," << left_move << "move : " << move << endl;
    // }
    cout << solution("ZZAAAZZ") << endl;
    // cout << solution("JEROEN") << endl;
}