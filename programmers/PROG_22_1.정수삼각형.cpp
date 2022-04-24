/*
DP문제
i번째 줄에올때
i-1번째 줄에 것과 더해야하는데
i번째 줄에서 맨 왼쪽은 i-1번째 맨 왼쪽것 그대로 더해서 내려오고
i번째 줄에서 맨 오른쪽은 i-1번째 맨 오른쪽것 그대로 더해서 내려오고
그럼 i번째 줄에서 맨왼쪽것과 맨 오른쪽것이 아닌 원소들이 중요한데
i-1번째에서 왼위쪽것과 오른위쪽것중 큰걸더하면 된다
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j - 1],triangle[i - 1][j]);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < triangle.size(); i++)
    {
        if (answer < triangle[triangle.size() - 1][i])
        {
            answer = triangle[triangle.size() - 1][i];
        }
    }
    return answer;
}

int main()
{
    cout << "ANSWER : " << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;
}

// for (int i = 0; i < triangle.size(); i++)
// {
//     for (int j = 0; j < triangle[i].size(); j++)
//     {
//         cout<<triangle[i][j]<< " ";
//     }
//     cout<<endl;
// }

                // int left = triangle[i - 1][j - 1];
                // int right = triangle[i - 1][j];
                // if (left > right)
                // {
                //     triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
                // }
                // else
                // {
                //     triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
                // }