#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    int limit = -30001;
    sort(routes.begin(), routes.end());

    for (int i = 0; i < routes.size(); i++)
    {
        if (limit < routes[i][0])
        {
            answer++;
            limit = routes[i][1];
        }
    }
    return answer;
}
int main()
{
    vector<vector<int>> a{{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}};
    int ans = solution(a);
    cout << ans;
}
// for (int i = 0; i < routes.size(); i++)
// {
//     for (int j = 0; j < 2; j++)
//     {
//         cout << routes[i][j] << " ";
//     }
//     cout << endl;
// }