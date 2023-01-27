/*
vector<vector<int>> move_cloud(int dir, int dist, vector<vector<int>> CLOUD)
여기가 틀림
*/
#include <iostream>
#include <vector>
using namespace std;

int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int magic_dr[4] = {-1, -1, 1, 1};
int magic_dc[4] = {-1, 1, -1, 1};
int N, M;

void print(vector<vector<int>> a)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
int abs(int a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}

vector<vector<int>> move_cloud(int dir, int dist, vector<vector<int>> CLOUD)
{
    vector<vector<int>> RETURN_CLOUD(N, vector<int>(N, 0));
    int move_dr_cnt = (dr[dir - 1]) * dist;
    int move_dc_cnt = (dc[dir - 1]) * dist;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (CLOUD[i][j] == 1)
            {
                int move_r = (i + move_dr_cnt) % N;
                int move_c = (j + move_dc_cnt) % N;
                if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= N)
                {
                    if (move_r < 0)
                    {
                        move_r = N - move_r;
                    }
                    if (move_c < 0)
                    {
                        move_c = N - move_c;
                    }
                    if (move_r >= N)
                    {
                        move_r = move_r % N;
                    }
                    if (move_c >= N)
                    {
                        move_c = move_c % N;
                    }
                }
                RETURN_CLOUD[move_r][move_c] = 1;
            }
        }
    }

    return RETURN_CLOUD;
}

vector<vector<int>> rain(vector<vector<int>> MAP, vector<vector<int>> CLOUD)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (CLOUD[i][j] == 1)
            {
                MAP[i][j] += 1;
            }
        }
    }
    return MAP;
}

vector<vector<int>> magic(vector<vector<int>> MAP, vector<vector<int>> CLOUD)
{
    vector<vector<int>> magic_map = MAP;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (CLOUD[i][j] == 1)
            {
                int add_water = 0;
                for (int k = 0; k < 4; k++)
                {
                    int move_r = i+ magic_dr[k];
                    int move_c = j + magic_dc[k];
                    if (move_r < 0 || move_c < 0 || move_r >= N || move_c >= N)
                        continue;
                    if (MAP[move_r][move_c] != 0)
                    {
                        add_water += 1;
                    }
                }
                MAP[i][j] += add_water;
            }
        }
    }
    return MAP;
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> MAP(N, vector<int>(N, 0));
    vector<vector<int>> COMMAND(M, vector<int>(2, 0));
    vector<vector<int>> CLOUD(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> COMMAND[i][j];
        }
    }

    CLOUD[N - 2][0] = 1;
    CLOUD[N - 1][0] = 1;
    CLOUD[N - 2][1] = 1;
    CLOUD[N - 1][1] = 1;
    for (int i = 0; i < M; i++)
    {
        CLOUD = move_cloud(COMMAND[i][0], COMMAND[i][1], CLOUD); //방향 칸수
        MAP = rain(MAP, CLOUD);
        MAP = magic(MAP, CLOUD);
        vector<vector<int>> temp_CLOUD(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAP[i][j] >= 2 && CLOUD[i][j] == 0)
                {
                    MAP[i][j] -= 2;
                    temp_CLOUD[i][j]=1;
                }
            }
        }
        CLOUD = temp_CLOUD;
        #if 0
        cout<<"MAP"<<endl;
        print(MAP);
        cout<<"CLOUD"<<endl;
        print(CLOUD);
        #endif
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer += MAP[i][j];
        }
    }
    cout << answer;
}