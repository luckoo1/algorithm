/*
void MOVE_SHARK()함수에서
vector<vector<vector<int>>> &MOVE_DIR
&안썼더니 시간초과 떴다.
*/

#include <iostream>
#include <vector>
using namespace std;
#define PRINT 0
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
int flag = 0;

void MOVE_SHARK(vector<vector<DATA>> &MAP, vector<int> &NOW_DIR, vector<vector<bool>> &NOW_SHARK_CHECK, vector<vector<DATA>> TEMP_MAP, int &total_shark, vector<vector<vector<int>>> &MOVE_DIR, int R, int C)
{

    int now_num = MAP[R][C].num;
    int now_smell = MAP[R][C].smell;
    int now_R = R;
    int now_C = C;
    int move_R;
    int move_C;
    int move_DIR;

    bool bin_kan_check = 0;
    for (int k = 0; k < 4; k++)
    {
        move_R = now_R + DR[MOVE_DIR[now_num][NOW_DIR[now_num]][k]];
        move_C = now_C + DC[MOVE_DIR[now_num][NOW_DIR[now_num]][k]];
        move_DIR = MOVE_DIR[now_num][NOW_DIR[now_num]][k];
        if (move_R < 0 || move_C < 0 || move_R >= N || move_C >= N)
            continue;
        if (TEMP_MAP[move_R][move_C].num == 0)
        {
            bin_kan_check = 1;
            break;
        }
    }

    if (bin_kan_check == 0)
    {
        for (int k = 0; k < 4; k++)
        {
            move_R = now_R + DR[MOVE_DIR[now_num][NOW_DIR[now_num]][k]];
            move_C = now_C + DC[MOVE_DIR[now_num][NOW_DIR[now_num]][k]];
            move_DIR = MOVE_DIR[now_num][NOW_DIR[now_num]][k];
            if (move_R < 0 || move_C < 0 || move_R >= N || move_C >= N)
                continue;
            if (TEMP_MAP[move_R][move_C].num == now_num)
                break;
        }
    }

    if (bin_kan_check == 1) /*빈 칸*/
    {
        if (MAP[move_R][move_C].smell == K) /*상어가 있다.*/
        {
            if (MAP[move_R][move_C].num < now_num)
            {
                NOW_SHARK_CHECK[now_R][now_C] = false;
                total_shark--;
                return;
            }
            total_shark--;
        }

        MAP[now_R][now_C] = DATA(now_num, K);
        MAP[move_R][move_C] = DATA(now_num, K);
        NOW_SHARK_CHECK[now_R][now_C] = false;
        NOW_SHARK_CHECK[move_R][move_C] = true;
        NOW_DIR[now_num] = move_DIR;
        return;
    }

    if (MAP[move_R][move_C].num == now_num) /*주변에 빈칸이 없다.내 냄새 구역으로*/
    {
        MAP[now_R][now_C] = DATA(now_num, K);
        MAP[move_R][move_C] = DATA(now_num, K);
        NOW_SHARK_CHECK[now_R][now_C] = false;
        NOW_SHARK_CHECK[move_R][move_C] = true;
        NOW_DIR[now_num] = move_DIR;
        return;
    }
}

void DELETE_SMELL(vector<vector<DATA>> &MAP, vector<vector<bool>> NOW_SHARK_CHECK)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (NOW_SHARK_CHECK[i][j] == false && MAP[i][j].num != 0)
            {
                MAP[i][j].smell -= 1;
                if (MAP[i][j].smell == 0)
                    MAP[i][j].num = 0;
            }
        }
    }
}

int main()
{
    int init_num;
    cin >> N >> M >> K;
    vector<vector<DATA>> MAP(N+1, vector<DATA>(N+1, DATA(0, 0)));
    vector<vector<bool>> NOW_SHARK_CHECK(N+1, vector<bool>(N+1, false));
    vector<vector<DATA>> TEMP_MAP(N+1, vector<DATA>(N+1, DATA(0, 0)));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> init_num;
            if (init_num > 0)
            {
                MAP[i][j] = DATA(init_num, K);
            }
            else
            {
                MAP[i][j] = DATA(init_num, 0);
            }
            if (init_num > 0)
                NOW_SHARK_CHECK[i][j] = true;
        }
    }

    vector<int> NOW_DIR;
    NOW_DIR.push_back(0);
    for (int i = 0; i < M; i++)
    {
        cin >> init_num;
        NOW_DIR.push_back(init_num - 1); // dir은 -1해서 넣음(0,1,2,3)
    }
    vector<vector<vector<int>>> MOVE_DIR(M + 3, vector<vector<int>>(4, vector<int>(4, 0)));
    for (int i = 1; i <= M; i++) //상어번호는 +1해서 넣음(1,2,3..M)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> init_num;
                MOVE_DIR[i][j][k] = init_num - 1; // dir은 -1해서 넣음(0,1,2,3)
            }
        }
    }
    int total_shark = M;
    int ans = 0;
    for (int DEP = 1; DEP <= 1000; DEP++)
    {
        if (flag == 1)
            break;

        vector<vector<bool>> TEMP_NOW_SHARK_CHECK = NOW_SHARK_CHECK;
        TEMP_MAP = MAP;
        ans = DEP;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (TEMP_NOW_SHARK_CHECK[i][j] == true)
                {
                    MOVE_SHARK(MAP, NOW_DIR, NOW_SHARK_CHECK, TEMP_MAP, total_shark, MOVE_DIR, i, j);
                }
                if (total_shark == 1)
                {
                    ans = DEP;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        DELETE_SMELL(MAP, NOW_SHARK_CHECK);
#if PRINT == 1
        cout << endl;
        cout << "DEP = " << DEP << endl;
        for (int i = 1; i <= M; i++)
        {
            cout << NOW_DIR[i] << " ";
        }
        cout << endl;
        cout << "MAP" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << "[" << MAP[i][j].num << "," << MAP[i][j].smell << "]";
            }
            cout << endl;
        }
        cout << "NOW_SHARK : " << total_shark << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << NOW_SHARK_CHECK[i][j] << " ";
            }
            cout << endl;
        }
#endif
    }
    if (flag == 0)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}