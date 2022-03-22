#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name)
{
    string temp_string = "";
    for (int i = 0; i < name.size(); i++)
        temp_string += 'A';

    int idx = 0;
    int move_cnt = 0;
    int cnt = 0;
    while (true)
    {
        if (temp_string == name)
            break;

        for (int i = 0; i < name.size(); i++)
        {
            int right_idx = (idx + i) % name.size();
            if (temp_string[right_idx] != name[right_idx])
            {
                idx = right_idx;
                move_cnt += i;
                break;
            }
            //cout << "right_idx : " << right_idx << endl;
            int left_idx = idx - i;
            if (left_idx < 0)
                left_idx += name.size();
            //cout << "left_idx : " << left_idx << endl;
            if (temp_string[(left_idx) % name.size()] != name[(left_idx) % name.size()])
            {
                idx = left_idx;
                move_cnt += i;
                break;
            }
        }
        int up_cnt = -(temp_string[idx] - name[idx]);
        int down_cnt = temp_string[idx] - name[idx] + 26;

        if (up_cnt >= down_cnt)
            move_cnt += down_cnt;
        else if (up_cnt < down_cnt)
            move_cnt += up_cnt;

        temp_string[idx] = name[idx];
        //cout << temp_string << " " << idx << endl;
    }

    return move_cnt;
}
int main()
{
    string a = "JEROEN";
    string b = "JAZ";
    string c = "AABAAB";

    int ans = solution(b);

    cout << ans;
}