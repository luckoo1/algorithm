#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ans = 0;

void dfs(int dep, int sum, int size, vector<int> &numbers, int &target)
{
    if (dep == size)
    {
        if (sum == target)
        {
            ans += 1;
        }
        return;
    }

    dfs(dep + 1, sum + numbers[dep], size, numbers, target);
    dfs(dep + 1, sum - numbers[dep], size, numbers, target);
}

int solution(vector<int> numbers, int target)
{
    dfs(0, 0, numbers.size(), numbers, target);
    int answer = ans;
    return answer;
}

int main()
{
    vector<int> a{1, 1, 1, 1, 1};
    int b = 3;
    int ans = solution(a, b);
    cout << ans;
}