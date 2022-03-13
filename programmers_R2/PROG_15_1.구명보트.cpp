#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(),people.end());

    

    return answer;
}

int main()
{
    cout << solution({70, 50, 80, 50}, 100) << endl;             // 3
    cout << solution({70, 80, 50}, 100) << endl;                 // 3
    cout << solution({40, 40, 40, 40, 40, 70, 80}, 100) << endl; // 3
}