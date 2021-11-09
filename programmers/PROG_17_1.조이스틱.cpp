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
    int move_cnt = 0;
    while (1)
    {
        int up_cnt = -(A[idx] - name[idx]);
        int down_cnt = A[idx] - name[idx] + 26;

        if (up_cnt >= down_cnt)
            move_cnt += down_cnt;
        else if (up_cnt < down_cnt)
            move_cnt += up_cnt;

        A[idx] = name[idx];

        if (A == name)
            break;

        move_cnt++;
    }
}
int main()
{
    // int a1 = -('A' - 'Z');
    // int b1 = 'A' - 'Y' + 26;
    string a1 = "JEROEN";
    string b1 = "AZ";

    int ans = solution(b1);

    cout << ans;
}