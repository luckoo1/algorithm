#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer = 0;
vector<int> vec;

void dfs(int x)
{
    int temp_ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != 0)
        {
            temp_ans += 1;
        }
    }
    if (answer < temp_ans)
    {
        answer = temp_ans;
    }
    for (int i = x; i < vec.size(); i++)
    {
        if (vec[i] == 2)
        {
            //왼쪽으로 빌려줌
            if (i != 0)
            {
                if (vec[i - 1] == 0 && vec[i] == 2)
                {
                    vec[i - 1] = 1;
                    vec[i] = 1;
                }
                dfs(i+1);
                vec[i - 1] = 0;
                vec[i] = 2;
            }

            //오른쪽으로 빌려줌
            if (i != vec.size() - 1)
            {
                if (vec[i] == 2 && vec[i + 1] == 0)
                {
                    vec[i + 1] = 1;
                    vec[i] = 1;
                }
                dfs(i+1);
                vec[i + 1] = 0;
                vec[i] = 2;
            }
        }
    }

    return;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
    for (int i = 0; i < n; i++)
    {
        vec.push_back(1);
    }
    for (int i = 0; i < lost.size(); i++)
    {
        vec[lost[i] - 1] -= 1;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        vec[reserve[i] - 1] += 1;
    }

    dfs(0);

    return answer;
}

int main()
{
    // int n1 = 5;
    // vector<int> a1{2, 4};
    // vector<int> b1{1, 3, 5};
    // cout << solution(n1, a1, b1) << endl;
    int n2 = 5;
    vector<int> a2{3,5};
    vector<int> b2{2,4};
    cout << solution(n2, a2, b2) << endl;
}