#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> a{1, 2, 3, 4, 5};                //5
    vector<int> b{2, 1, 2, 3, 2, 4, 2, 5};       //8
    vector<int> c{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; //10

    vector<int> cnt(3, 0);

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a[i % 5])
            cnt[0]++;
        if (answers[i] == b[i % 8])
            cnt[1]++;
        if (answers[i] == c[i % 10])
            cnt[2]++;
    }

    int biggest_num = *max_element(cnt.begin(), cnt.end());

    vector<int> answer;
    for (int i = 0; i < 3; i++)
    {
        if (biggest_num == cnt[i])
            answer.push_back(i + 1);
    }
    return answer;
}

int main()
{
    vector<int> a1{1, 2, 3, 4, 5};
    vector<int> b1{1, 3, 2, 4, 2};

    vector<int> ans1 = solution(a1);
    vector<int> ans2 = solution(b1);
}