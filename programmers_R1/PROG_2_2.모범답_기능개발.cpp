#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1; //기능개발까지 필요한 day
        // 1번 case의 day : 7 3 9
        // 2번 case의 day : 5 10 1 1 20 1
        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
        // 1번 case의 max_day : 7 7 9
        // 2번 case의 max_day : 5 10 10 10 20 20
    }

    return answer;
}

int main()
{
    vector<int> a1{93, 30, 55};
    vector<int> a2{1, 30, 5};
    vector<int> b1{95, 90, 99, 99, 80, 99};
    vector<int> b2{1, 1, 1, 1, 1, 1};
    vector<int> answer = solution(a1, a2);
    cout << endl;
    for (auto n : answer)
    {
        cout << n << " ";
    }
}