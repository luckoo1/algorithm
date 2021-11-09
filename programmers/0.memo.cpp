#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name)
{
    string A = "";
    for (int i = 0; i < name.size(); i++)
        A += 'A';

    int idx = 0;
    int right_move_way = 0;
    while (1)
    {
        if (A[idx] == name[idx])
        {
            idx += 1;
            continue;
        }
        int up_cnt = -(A[idx] - name[idx]);
        int down_cnt = A[idx] - name[idx] + 26;

        if (up_cnt >= down_cnt)
            right_move_way += down_cnt;
        else if (up_cnt < down_cnt)
            right_move_way += up_cnt;

        A[idx] = name[idx];
        idx++;
        if (A == name)
        {
            break;
        }
        right_move_way++;
    }

    A = "";
    for (int i = 0; i < name.size(); i++)
        A += 'A';
    int left_move_way = 0;

    if (A[0] != name[0])
    {
        int up_cnt = -(A[0] - name[0]);
        int down_cnt = A[0] - name[0] + 26;

        if (up_cnt >= down_cnt)
            left_move_way += down_cnt;
        else if (up_cnt < down_cnt)
            left_move_way += up_cnt;
    }

    idx = name.size() - 1;
    while (1)
    {
        if (A[idx] == name[idx])
        {
            idx -= 1;
            continue;
        }
        int up_cnt = -(A[idx] - name[idx]);
        int down_cnt = A[idx] - name[idx] + 26;

        if (up_cnt >= down_cnt)
            left_move_way += down_cnt;
        else if (up_cnt < down_cnt)
            left_move_way += up_cnt;

        A[idx] = name[idx];
        idx--;
        if (A == name)
        {
            break;
        }
        left_move_way++;
    }

    if (right_move_way > left_move_way)
        return left_move_way;
    else
        return right_move_way;
}
int main()
{
    // int a1 = -('A' - 'Z');
    // int b1 = 'A' - 'Y' + 26;
    string a1 = "ABAAAAAAAAABB";
    string b1 = "JAZ";

    int ans = solution(b1);

    cout << ans;
}