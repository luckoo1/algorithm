#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

void print_check(vector<vector<bool>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void print_vec(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
struct DATA
{
    int r;
    int c;

    DATA(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};
int DR[4] = {0, 0, 1, -1};
int DC[4] = {1, -1, 0, 0};

queue<DATA> q;

vector<vector<int>> solution(int x, int y, vector<vector<int>> board)
{
    print_vec(board);
    int r_size = board.size();
    int c_size = board[0].size();
    vector<vector<int>> dist_map(r_size, vector<int>(c_size, 0));
    vector<vector<bool>> check(r_size, vector<bool>(c_size, false));

    q.push(DATA(x - 1, y - 1));
    check[x - 1][y - 1] = true;

    while (!q.empty())
    {
        int start_r = q.front().r;
        int start_c = q.front().c;
        int start_dist = dist_map[start_r][start_c];
        int start_score = board[start_r][start_c];
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int move_r = start_r + DR[k];
            int move_c = start_c + DC[k];
            if (move_r < 0 || move_c < 0 || move_r >= r_size || move_c >= c_size)
                continue;
            if (move_r == x - 1 && move_c == y - 1)
                continue;
            if (check[move_r][move_c] == true)
            {
                if (board[move_r][move_c] == start_score)
                {
                    if (dist_map[move_r][move_c] > start_dist)
                    {
                        dist_map[move_r][move_c] = start_dist;
                    }
                }
                else
                {
                    if (dist_map[move_r][move_c] > start_dist + 1)
                    {
                        dist_map[move_r][move_c] = start_dist + 1;
                    }
                }
                continue;
            }

            if (board[move_r][move_c] == start_score)
            {
                q.push(DATA(move_r, move_c));
                dist_map[move_r][move_c] = start_dist;
            }
            else
            {
                q.push(DATA(move_r, move_c));
                dist_map[move_r][move_c] = start_dist + 1;
            }
            check[move_r][move_c] = true;
        }

        // cout << "PRINT" << endl;
        // print_vec(dist_map);
        // cout << "=== CHECK ===" << endl;
        // print_check(check);
        //cout << endl;
    }

    map<int, int> hash_map;
    for (int i = 0; i < dist_map.size(); i++)
    {
        for (int j = 0; j < dist_map[0].size(); j++)
        {
            hash_map[dist_map[i][j]] += 1;
        }
    }
    int max_num = 0;
    int big_diff = 0;
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        if (max_num <= iter->second)
        {
            max_num = iter->second;
            big_diff = iter->first;
        }
    }

    // for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    // {
    //     cout<<iter->first<<" "<<iter->second<<endl;
    // }
    vector<vector<int>> answer;
    for (int i = 0; i < dist_map.size(); i++)
    {
        for (int j = 0; j < dist_map[0].size(); j++)
        {
            if (dist_map[i][j] == big_diff)
                answer.push_back({i + 1, j + 1});
        }
    }
    return answer;
}

int main()
{
    #if 1
    vector<vector<int>> vec{
        {5, 4, 3, 4, 4, 4},
        {1, 3, 2, 3, 3, 5},
        {2, 3, 4, 5, 5, 1},
        {2, 2, 3, 4, 4, 3}};
    vector<vector<int>> ans = solution(3, 2, vec);
    #endif
    #if 0
    vector<vector<int>> vec{
        {7,9,7,9,7},
        {9,7,9,7,9},
        {7,9,7,9,7},
        {9,7,9,7,9},
        {7,9,7,9,7}};
    vector<vector<int>> ans = solution(3, 3, vec);
    #endif

    // print_vec(vec);
    // cout << "RESULT" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
/*
3, 2
5 4 3 4 4 4
1 3 2 3 3 5
2 3 4 5 5 1
2 2 3 4 4 3

14
15
16
26
36
44
45

79797
97979
79797
97979
79797
12
14
21
25
41
45
52
54
*/