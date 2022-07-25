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
        vec[M - 1] = temp;
    }
}

float get_average(vector<vector<int>> vec)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum += vec[i][j];
            if(vec[i][j]!=0)
            {
                cnt++;
            }
        }
    }
    return sum / (double)cnt;
}

vector<vector<bool>> check_vec(vector<vector<int>> MAP)
{
    vector<vector<bool>> check(N, vector<bool>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (MAP[i][j] == 0)
                continue;
            if (MAP[i][j] == MAP[i][(j + 1) % M])
            {
                check[i][j] = true;
                check[i][(j + 1) % M] = true;
            }

            if (i != N - 1)
            {
                if (MAP[i][j] == MAP[i + 1][j])
                {
                    check[i][j] = true;
                    check[i + 1][j] = true;
                }
            }
        }
    }

    return check;
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

    for (int i = 0; i < T; i++)
    {
        int bae_soo = COMMAND[i][0];
        int wise = COMMAND[i][1];
        int how_many = COMMAND[i][2];
        for (int j = bae_soo; j <= M; j += bae_soo)
        {
            if (wise == 0)
            {
                clock_rotate(MAP[j - 1], how_many);
            }
            else if (wise == 1)
            {
                ban_rotate(MAP[j - 1], how_many);
            }
        }

        int flag = 0;
        vector<vector<bool>> check = check_vec(MAP);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (check[i][j] == true)
                {
                    flag = 1;
                    MAP[i][j] = 0;
                }
            }
        }
        PRINT_VEC(MAP);
        cout << endl;
        if (flag == 0)
        {
            float avg = get_average(MAP);
            cout<<avg<<endl;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (MAP[i][j] != 0)
                    {
                        if ( (double)MAP[i][j] < avg)
                        {
                            MAP[i][j] += 1;
                        }
                        if ( (double)MAP[i][j] >avg)
                        {
                            MAP[i][j] -= 1;
                        }
                    }
                }
            }
        }
    }
    PRINT_VEC(MAP);
    cout << endl;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum += MAP[i][j];
        }
    }
    cout << sum;
}