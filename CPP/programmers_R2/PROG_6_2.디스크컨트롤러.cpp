#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0;  // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

    while (!jobs.empty())
    {
        for (int i = 0; i < jobs.size(); i++)
        {
            if (jobs[i][0] <= start) // 신호시작 시간이면
            {
                start = start + jobs[i][1];
                time = time + (start - jobs[i][0]);
                cout << time << endl;
                jobs.erase(jobs.begin() + i);
                break;
            }

            if (i == jobs.size() - 1)
                start++;
        }
    }

    answer = time / size;
    return answer;
}

int main()
{
    vector<vector<int>> a = {{0, 3}, {1, 9}, {2, 6}};
    int ans = solution(a);
    cout << "\n\n"
         << ans;
}