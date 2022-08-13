#include <iostream>
#include <vector>
using namespace std;

struct DATA
{
    int num;
    int smell;
    DATA(int num, int smell)
    {
        this->num = num;
        this->smell = smell;
    }
};
int DR[4] = {-1, 1, 0, 0};
int DC[4] = {0, 0, -1, 1};
/*위,아래,왼,오*/
int N, M, K;

int main()
{
    int init_num;
    cin >> N >> M >> K;
    vector<vector<DATA>> MAP(N, vector<DATA>(N, DATA(0,0)));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MAP[i][j] = DATA(init_num, K);
        }
    }

    vector<int> NOW_DIR;
    for (int i = 0; i < M; i++)
    {
        cin >> init_num;
        NOW_DIR.push_back(init_num - 1); //dir은 -1해서 넣음
    }

    vector<vector<vector<int>>> MOVE_DIR(M + 1, vector<vector<int>>(4, vector<int>(4, 0)));
    for (int i = 1; i <= M; i++) //상어번호는 +1해서 넣어서 바로
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> init_num;
                MOVE_DIR[i][j][k] = init_num - 1; //dir은 -1해서 넣음
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            
        }
    }
    
}