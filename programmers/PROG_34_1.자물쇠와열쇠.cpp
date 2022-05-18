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

void move_up()
{
    
}
void move_down()
{

}
void move_left()
{

}
void move_right()
{

}

int count_num(vector<vector<int>> map, int num)
{
    int N = map.size();
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == num)
            {
                sum += 1;
            }
        }
    }
    return sum;
}

bool check_lock(vector<vector<int>> key, vector<vector<int>> lock)
{
    int lock_cnt = count_num(lock, 0); // lock에서 0의수
    int key_cnt = count_num(key, 1);
    if (lock_cnt != key_cnt)
    {
        return false;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = true;
    rotate(key);
    return answer;
}

int main()
{

    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
}