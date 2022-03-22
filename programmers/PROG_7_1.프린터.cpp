/*
그래서 sort를 정책을 사용해서 풀려고 했다.
vector에 {{1,1},{1,2},{9,3},{1,4},{1,5},{1,6}}으로 담았다.
그래서 sort를 할때 {{9,3},{1,4},{1,5},{1,6},{1,1},{1,2}}순서로 되게하고 싶었는데 그게 잘 되지않았다.
다음에 시도하면 좋을거 같다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
    vector<int> idx_vec;
    int ans = 1;
    for (int i = 0; i < priorities.size(); i++)
    {
        idx_vec.push_back(i);
    }

    int idx = max_element(priorities.begin(), priorities.end()) - priorities.begin();

    while(1)
    {

        int max_number = *max_element(priorities.begin(), priorities.end());

        if (idx_vec[idx] == location && priorities[idx] == max_number)
        {
            return ans;
        }
        else if (priorities[idx] == max_number)
        {
            priorities[idx] = 0;
            ans += 1;
        }

        idx = (idx + 1) % priorities.size();
    }
}

int main()
{
    vector<int> a{2, 1, 3, 2};
    int b = 2;
    vector<int> c{1, 1, 9, 8, 1, 1};
    int d = 0;

    int answer = solution(c, d);
    cout << answer;
}