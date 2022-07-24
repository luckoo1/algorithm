#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
void PRINT_VEC(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

void clock_rotate(vector<int> &vec, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = vec[M - 1];
        for (int i = M - 1; i >= 1; i--)
        {
            vec[i] = vec[i - 1];
        }
        vec[0] = temp;
    }
}
void ban_rotate(vector<int> &vec, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = vec[0];
        for (int i = 0; i < M - 1; i++)
        {
            vec[i] = vec[i + 1];
        }
        vec[M-1] = temp;
    }
}

int get_average(vector<vector<int>> vec)
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum += vec[i][j];
        }
    }
    return sum / (N * M);
}

int main()
{
    cin >> N >> M >> T;

    vector<vector<int>> MAP(N, vector<int>(M, 0));
    vector<vector<int>> COMMAND(T, vector<int>(3, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> COMMAND[i][j];
        }
    }
    clock_rotate(MAP[0],1);
    ban_rotate(MAP[1], 1);

    PRINT_VEC(MAP);
    PRINT_VEC(COMMAND);
}