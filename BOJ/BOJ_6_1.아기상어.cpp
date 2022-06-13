#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct DATA
{
    int row;
    int col;
    DATA(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

int N;
vector<vector<int>> MAP(20, vector<int>(20, 0));
int shark_row, shark_col, shark_size;
map<int, DATA> hash_map;

int main()
{

    cin >> N;
    int shark_size = 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 9)
            {
                shark_row = i;
                shark_col = j;
            }
            if (MAP[i][j] != 9 && MAP[i][j] != 0)
            {
                hash_map[MAP[i][j]] = DATA(i, j);
            }
        }
    }

    vector<int> fish = {1, 2, 3, 4, 5, 6, 9};

    for (auto fish_size : fish)
    {
    }
}