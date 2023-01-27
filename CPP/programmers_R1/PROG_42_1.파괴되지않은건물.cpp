/*효율성 0점*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    for (auto skill : skill)
    {
        int type = skill[0];
        int how_many = skill[5];
        if (type == 1)
        {
            for (int i = skill[1]; i <= skill[3]; i++)
            {
                for (int j = skill[2]; j <= skill[4]; j++)
                {
                    board[i][j] -= how_many;
                }
            }
        }
        if (type == 2)
        {
            for (int i = skill[1]; i <= skill[3]; i++)
            {
                for (int j = skill[2]; j <= skill[4]; j++)
                {
                    board[i][j] += how_many;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] > 0)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{

#if 1
    cout << solution({{5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5}},
                     {{1, 0, 0, 3, 4, 4},
                      {1, 2, 0, 2, 3, 2},
                      {2, 1, 0, 3, 1, 2},
                      {1, 0, 1, 3, 3, 1}})
         << endl;
    cout << solution({{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}},
                     {{1, 1, 1, 2, 2, 4},
                      {1, 0, 0, 1, 1, 2},
                      {2, 2, 0, 2, 0, 100}})
         << endl;
#endif
}