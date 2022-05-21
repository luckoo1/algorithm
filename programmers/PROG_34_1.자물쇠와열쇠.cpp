#include <string>
#include <vector>
#include <iostream>
using namespace std;

int key_size;
int lock_size;
int open_size;
bool check[999][999];

void rotate(vector<vector<int>> &key)
{
    vector<vector<int>> temp(key_size, vector<int>(key_size));
    for (int i = 0; i < key_size; i++)
    {
        for (int j = 0; j < key_size; j++)
        {
            temp[i][j] = key[j][key_size - i - 1];
        }
    }
    key = temp;
}

bool check_key(int row, int col, vector<vector<int>> &key_big, vector<vector<int>> &lock)
{
    int cnt = 0;
    for (int i = row; i < row + lock_size; i++)
    {
        for (int j = col; j < col + lock_size; j++)
        {
            if(key_big[i][j] == 1 && lock[i - row][j - col] == 1)
            {
                return false;
            }
            if (key_big[i][j] == 1 && lock[i - row][j - col] == 0 && check[i - row][j - col] == true)
            {
                cnt++;
            }
        }
    }
    if (cnt == open_size)
    {
        return true;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    key_size = key.size();
    lock_size = lock.size();
    open_size = 0;
    int map_size = (lock_size * 2) + (key_size - 2);
    vector<vector<int>> key_big(map_size, vector<int>(map_size));
    for (int i = 0; i < lock_size; i++)
    {
        for (int j = 0; j < lock_size; j++)
        {
            if (lock[i][j] == 0)
            {
                open_size += 1;
                check[i][j] = true;
            }
        }
    }

    int dir = 4;
    while (dir--)
    {
        for (int i = lock_size - 1; i < lock_size + key_size - 1; i++)
        {
            for (int j = lock_size - 1; j < lock_size + key_size - 1; j++)
            {
                key_big[i][j] = key[i - lock_size + 1][j - lock_size + 1];
            }
        }

        for (int i = 0; i < map_size - lock_size + 1; i++)
        {
            for (int j = 0; j < map_size - lock_size + 1; j++)
            {
                if (check_key(i, j, key_big, lock) == true)
                {
                    return true;
                }
            }
        }
        rotate(key);
    }

    return false;
}

int main()
{

    cout << solution({{0, 0, 0},
                      {1, 0, 0},
                      {0, 1, 1}},
                     {{1, 1, 1},
                      {1, 1, 0},
                      {1, 0, 1}});
}

// for(int i=0;i<map_size;i++)
// {
//     for(int j=0;j<map_size;j++)
//     {
//         cout<<key_big[i][j]<<" ";
//     }
//     cout<<endl;
// }