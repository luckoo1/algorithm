// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// bool sort_rule(int &a, int &b)
// {
//     return a > b;
// }

// int solution(vector<int> citations)
// {
//     sort(citations.begin(), citations.end(), sort_rule);

//     for (int i = 0; i < citations.size(); i++)
//     {
//     }

//     int answer = 0;
//     return answer;
// }

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>()); // citations를 내림차순 정렬

    for (int i = 0; i < citations.size(); i++)
    {
        if (i + 1 <= citations[i])
            answer = i + 1;
        else
            break;
    }

    return answer;
}

int main()
{
    vector<int> a1{1, 7, 0, 1, 6, 4};               //3
    vector<int> a2{1545, 2, 999, 790, 540, 10, 22}; //6
    int ans = solution(a2);
    cout << ans;
}