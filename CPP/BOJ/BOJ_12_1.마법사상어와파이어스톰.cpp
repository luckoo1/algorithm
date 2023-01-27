#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, L;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

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

void print(vector<vector<int>> MAP)
{
    cout << "PRINT" << endl;
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>> &MAP, int magic_size, int start_row, int start_col)
{
    vector<vector<int>> temp_map;
    vector<vector<int>> cut_map;
    vector<int> temp;
    for (int i = start_row; i < start_row + magic_size; i++)
    {
        for (int j = start_col; j < start_col + magic_size; j++)
        {
            temp.push_back(MAP[i][j]);
        }
        cut_map.push_back(temp);
        temp.clear();
    }
    temp.clear();
    for (int j = 0; j < magic_size; j++)
    {
        for (int i = magic_size - 1; i >= 0; i--) //범위 잘 생각하기
        {
            temp.push_back(cut_map[i][j]);
        }
        temp_map.push_back(temp);
        temp.clear();
    }

    for (int i = start_row; i < start_row + magic_size; i++)
    {
        for (int j = start_col; j < start_col + magic_size; j++)
        {
            MAP[i][j] = temp_map[i - start_row][j - start_col];
        }
    }
}

void ice(vector<vector<int>> &MAP, int MAP_SIZE)
{
    vector<vector<bool>> check(MAP.size(), vector<bool>(MAP.size(), false));
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (MAP[i][j] == 0)
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int move_dr = i + dr[k];
                int move_dc = j + dc[k];
                if (move_dr < 0 || move_dc < 0 || move_dr >= MAP_SIZE || move_dc >= MAP_SIZE)
                    continue;
                if (MAP[move_dr][move_dc] != 0)
                {
                    cnt++;
                }
            }
            if (cnt < 3)
            {
                check[i][j] = true;
            }
        }
    }

    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (check[i][j] == true)
            {
                MAP[i][j] -= 1;
            }
        }
    }
}
int main()
{
    cin >> N >> L;
    int MAP_SIZE = pow(2, N);
    vector<vector<int>> MAP(MAP_SIZE, vector<int>(MAP_SIZE, 0));
    vector<int> magic;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            cin >> MAP[i][j];
        }
    }
    int magic_num;
    while (L--)
    {
        cin >> magic_num;
        magic.push_back(magic_num);
    }
    for (int k = 0; k < magic.size(); k++)
    {
        for (int i = 0; i < MAP_SIZE; i += pow(2, magic[k]))
        {
            for (int j = 0; j < MAP_SIZE; j += pow(2, magic[k]))
            {
                if (magic[k] != 0)
                {
                    rotate(MAP, pow(2, magic[k]), i, j);
                }
            }
        }
        ice(MAP, MAP_SIZE);
    }

    int ans = 0;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            ans += MAP[i][j];
        }
    }
    vector<vector<int>> check(MAP_SIZE, vector<int>(MAP_SIZE, 0));
    int max_ans = 0;
    queue<DATA> q;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            int temp_max = 0;
            if (MAP[i][j] != 0 && check[i][j] == false)
            {
                q.push(DATA(i, j));
                temp_max+=1;
                while (!q.empty())
                {
                    int now_r = q.front().r;
                    int now_c = q.front().c;
                    check[now_r][now_c] = true;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int move_r = now_r + dr[k];
                        int move_c = now_c + dc[k];
                        if (move_r < 0 || move_c < 0 || move_r >= MAP_SIZE || move_c >= MAP_SIZE)
                            continue;
                        if (MAP[move_r][move_c] == 0||check[move_r][move_c] == true)
                            continue;
                        q.push(DATA(move_r, move_c));
                        check[move_r][move_c] = true;
                        temp_max++;
                    }
                }
                if (temp_max > max_ans)
                {
                    max_ans = temp_max;
                }
            }
        }
    }

    cout << ans << " " << max_ans;
}