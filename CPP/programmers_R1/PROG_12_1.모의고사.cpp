#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> ans;
    vector<int> a{1, 2, 3, 4, 5};  //size 5
    vector<int> b{2, 1, 2, 3, 2, 4, 2, 5,}; //size 8
    vector<int> c{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; //size 10

    vector<int> cnt{0, 0, 0};

    for (int i = 0; i < answers.size();i++)
    {
        if(answers[i]==a[i%5])
            cnt[0] += 1;
        if(answers[i]==b[i%8])
            cnt[1] += 1;
        if(answers[i]==c[i%10])
            cnt[2] += 1;
    }

    int biggest_num = *max_element(cnt.begin(),cnt.end());
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] == biggest_num)
            ans.push_back(i + 1);
    }

    return ans;
}

int main()
{
    vector<int> a{1,2,3,4,5};
    vector<int> b{1, 3, 2, 4, 2};
    vector<int> ans1 = solution(a);
    for(auto n: ans1)
    {
        cout << n << " ";
    }
    cout << endl;
    vector<int> ans2 = solution(b);
    for (auto n : ans2)
    {
        cout << n << " ";
    }
    cout << endl;
}
/*
vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> a{1, 2, 3, 4, 5};  //size 5
    vector<int> b{2, 1, 2, 3, 2, 4, 2, 5,}; //size 8
    vector<int> c{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; //size 10

    int a_cnt = 0;
    int b_cnt = 0;
    int c_cnt = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a[i % 5])
        {
            a_cnt += 1;
        }
        if (answers[i] == b[i % 8])
        {
            b_cnt += 1;
        }
        if (answers[i] == c[i % 10])
        {
            c_cnt += 1;
        }
    }

    int biggest_ans = 0;
    if(a_cnt > b_cnt)
    {
        biggest_ans = a_cnt;
    }
    else
    {
        biggest_ans = b_cnt;
    }
    if(c_cnt>biggest_ans)
    {
        biggest_ans = c_cnt;
    }

    if (a_cnt == biggest_ans)
    {
        answer.push_back(1);
    }
    if (b_cnt == biggest_ans)
    {
        answer.push_back(2);
    }
    if (c_cnt == biggest_ans)
    {
        answer.push_back(3);
    }

    return answer;
}

*/