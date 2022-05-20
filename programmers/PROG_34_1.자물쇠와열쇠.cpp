#include <string>
#include <vector>
#include <iostream>
using namespace std;

int key_size;
int lock_size;

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


bool check_lock(vector<vector<int>> &key, vector<vector<int>> &lock, vector<vector<int>> &check_map)
{
    for (int i = 0; i < key_size; i++)
    {
        for (int j = 0; j < key_size; j++)
        {
            check_map[i][j] = key[i][j];
        }
    }

    int key_move = key_size + lock_size - 1;

    for (int i = 0; i < key_move; i++)
    {
        for (int j = 0; j < key_move; j++)
        {
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    key_size = key.size();
    lock_size = lock.size();
    int check_lock_size = (key_size * 2) + (lock_size - 2);

    vector<vector<int>> check_map(check_lock_size, vector<int>(check_lock_size));

    return true;
}

int main()
{

    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
}