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