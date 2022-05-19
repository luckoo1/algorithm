#include <string>
#include <vector>
#include <iostream>
using namespace std;

void rotate(vector<vector<int>> &key)
{
    int N = key.size();
    vector<vector<int>> temp(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = key[j][N - i - 1];
        }
    }
    key = temp;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int key_size = key.size();
    int lock_size = lock.size();

    return true;
}

int main()
{

    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
}