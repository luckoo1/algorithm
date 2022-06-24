#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, L;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

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
        for (int i = 0; i < MAP_SIZE; i += pow(2,magic[k]))
        {
            for (int j = 0; j < MAP_SIZE; j += pow(2,magic[k]))
            {
                if (magic[k] != 0)
                {
                    rotate(MAP, pow(2, magic[k]), i, j);
                }
            }
        }
        print(MAP);
    }
    int ans=0;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            ans+=MAP[i][j];
        }
    }
    cout<<ans;
}