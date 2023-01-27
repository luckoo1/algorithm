//답본것
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;
 
int N, M, K;
int row, col, age;
vector<vector<int>> ENERGY(12, vector<int>(12, 5));
vector<vector<int>> PLUS_ENERGY(12, vector<int>(12, 0));
deque<int> trees[11][11];

int DR[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int DC[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> PLUS_ENERGY[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> row >> col >> age;
        trees[row][col].push_back(age);
    }
    //----------------------------------------------------------------------------------
    for (int X = 0; X < K; X++)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                // 양분 먹고 나이 +1
                int k = 0;
                for (; k < trees[i][j].size(); ++k)
                {
                    if (ENERGY[i][j] >= trees[i][j][k])
                    {
                        ENERGY[i][j] -= trees[i][j][k];
                        trees[i][j][k]++;
                    }
                    else
                    {
                        break;
                    }
                }
                // 여름
                // 죽은 나무 있는 곳 양분 추가
                for (int p = trees[i][j].size() - 1; p >= k; --p)
                {
                    ENERGY[i][j] += trees[i][j][p] / 2;
                    trees[i][j].pop_back();
                }

                for(int x = 0;x<trees[i][j].size();x++)
                {
                    if(trees[i][j][x]>0)
                    {
                    cout<<trees[i][j][x]<<" ";
                    }
                }

            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {

                for (int k = 0; k < trees[i][j].size(); k++)
                {
                    if ((trees[i][j][k]) % 5 == 0)
                    {
                        int row = i;
                        int col = j;
                        for (int k = 0; k < 8; k++)
                        {
                            int move_row = row + DR[k];
                            int move_col = col + DC[k];
                            if (move_row < 1 || move_col < 1 || move_row > N || move_col > N)
                            {
                                continue;
                            }
                            trees[move_row][move_col].push_front(1);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                ENERGY[i][j] += PLUS_ENERGY[i][j];
            }
        }
    }

    int tree_cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (trees[i][j].size() > 0)
            {
                tree_cnt += trees[i][j].size();
            }
        }
    }
    cout << tree_cnt;
}