#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int left_idx = 0;
    int right_idx = people.size() - 1;
    sort(people.begin(), people.end());

    while (left_idx <= right_idx)
    {
        if (people[left_idx] + people[right_idx] <= limit)
        {
            left_idx++;
            right_idx--;
        }
        else
        {
            right_idx--;
        }
        answer++;
    }
    return answer;
}
int main()
{
    vector<int> a{1, 2, 3, 4, 5, 7};
    int b = 6;
    int ans = solution(a, b);
    cout << endl;
    cout << "answer : " << ans;
}