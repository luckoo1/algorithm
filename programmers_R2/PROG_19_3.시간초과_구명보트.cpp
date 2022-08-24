#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool sort_rule(int a, int b)
{
    return a > b;
}

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end(), sort_rule);
    int cnt = 0;

    while (!people.empty())
    {
        if (people.size() == 1)
        {
            cnt += 1;
            break;
        }

        if (people[0] + people[people.size() - 1] > limit)
        {
            people.erase(people.begin());
            cnt += 1;
        }
        else if (people[0] + people[people.size() - 1] <= limit)
        {
            people.erase(people.begin());
            people.pop_back();
            cnt += 1;
        }
    }

    return cnt;
}
int main()
{
    vector<int> a{70, 80, 50};
    int b = 100;
    int ans = solution(a, b);
    cout << endl;
    cout << "answer : " << ans;
}