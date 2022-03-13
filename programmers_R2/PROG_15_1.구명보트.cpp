#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());
    int small_idx = 0;
    int big_idx = people.size() - 1;

    while (small_idx <= big_idx)
    {
        if (people[small_idx] + people[big_idx] > limit)
        {
            big_idx -= 1;
        }
        else
        {
            small_idx += 1;
            big_idx -= 1;
        }
        answer += 1;
    }

    return answer;
}
int main()
{
    cout << solution({70, 50, 80, 50}, 100) << endl; // 3
    cout << solution({70, 80, 50}, 100) << endl;     // 3
    // cout << solution({40, 40, 40, 40, 40, 70, 80}, 100) << endl; // 3
}

//시간초과
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());
    while (true)
    {
        if (people.size() == 1)
        {
            answer += 1;
            break;
        }
        else if (people.size() == 0)
        {
            break;
        }

        if (people[0] + people[people.size() - 1] <= limit)
        {
            people.erase(people.end() - 1);
            people.erase(people.begin());
            answer += 1;
        }
        else
        {
            people.erase(people.end() - 1);
            answer += 1;
        }
    }

    return answer;
}

*/