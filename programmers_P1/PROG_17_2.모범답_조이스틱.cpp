#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int LUT[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int solution(string name)
{
    int answer = 0;
    for (auto ch : name)
        answer += LUT[ch - 'A']; //일단 돌면서 차이나는 만큼 더한다.

    int len = name.length();
    int left_right = len - 1; //끝에부터 시작

    for (int i = 0; i < len; ++i)
    {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, (i + len) - next_i + min(i, len - next_i));

        cout << left_right << " " << i + len << "-" << next_i << "+" << min(i, len - next_i) << endl;
        cout << i << " " << len << "-" << next_i << endl;
    }
    answer += left_right;
    return answer;
}

int main()
{
    string a = "JEROEN";
    string b = "JAZ";
    string c = "AABAAB";

    int ans = solution(c);

    cout << ans;
}

/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int LUT[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int solution(string name)
{
    int answer = 0;
    for (auto ch : name)
        answer += LUT[ch - 'A']; //일단 돌면서 차이나는 만큼 더한다.

    int len = name.length();
    int left_right = len - 1; //끝에부터 시작

    for (int i = 0; i < len; ++i)
    {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, (i + len) - next_i + min(i, len - next_i));

        cout << left_right << " " << i + len << "-" << next_i << "+" << min(i, len - next_i) << endl;
        cout << i << "," << len << " -" << next_i << endl;
        cout << endl;
    }
    answer += left_right;
    return answer;
}

int main()
{
    string a = "JEROEN";
    string b = "JAZ";
    string c = "AABAAB";

    int ans = solution(c);

    cout << ans;
}
*/