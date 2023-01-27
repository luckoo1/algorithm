/*
문제를 잘읽자!!!
문제에서 [0][0]을 [1][1]로 정의함을 잊었다.
이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
#define PRINT 0
struct DATA
{
    int m;
    int s;
    int d;
    DATA(int m, int s, int d)
    {
        this->m = m;
        this->s = s;
        this->d = d;
    }
};
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, K;
int r, c, m, s, d;
deque<DATA> MAP[51][51];
deque<DATA> After_Move_MAP[51][51];
deque<DATA> After_Calc_MAP[51][51];

void move()
{
    //========================================
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            After_Move_MAP[i][j].clear();
        }
    }
    //========================================
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j].size() != 0)
            {
                while (!MAP[i][j].empty())
                {
                    int move_row = i;
                    int move_col = j;
                    int m = MAP[i][j].front().m;
                    int s = MAP[i][j].front().s;
                    int d = MAP[i][j].front().d;
                    for (int k = 0; k < s; k++)
                    {
                        move_row += dr[d];
                        move_col += dc[d];
                        if (move_row < 0)
                        {
                            move_row = N - 1;
                        }
                        if (move_col < 0)
                        {
                            move_col = N - 1;
                        }
                        if (move_row >= N)
                        {
                            move_row = 0;
                        }
                        if (move_col >= N)
                        {
                            move_col = 0;
                        }
                    }
                    MAP[i][j].pop_front();
                    After_Move_MAP[move_row][move_col].push_back(DATA(m, s, d));
                }
            }
        }
    }
}

void calc()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            After_Calc_MAP[i][j].clear();
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (After_Move_MAP[i][j].size() >= 2) /*문제를 잘읽자*/
            {
                int sum_m = 0;
                int sum_s = 0;
                int flag = 0;
                int KAN_SIZE = After_Move_MAP[i][j].size();
                int check_flag = After_Move_MAP[i][j].front().d % 2;
                while (!After_Move_MAP[i][j].empty())
                {
                    int m = After_Move_MAP[i][j].front().m;
                    int s = After_Move_MAP[i][j].front().s;
                    int d = After_Move_MAP[i][j].front().d;
                    sum_m += m;
                    sum_s += s;
                    if (check_flag != d % 2)
                    {
                        flag = 1;
                    }
                    After_Move_MAP[i][j].pop_front();
                }
                sum_m = sum_m / 5;
                sum_s = sum_s / KAN_SIZE;
                #if PRINT
                cout<<sum_m<<" "<<flag<<endl;
                #endif
                if (sum_m == 0)
                {
                    continue;
                }
                if (flag == 0)
                {
                    #if PRINT
                    cout<<"FLAG 0"<<endl;
                    #endif
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 0));
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 2));
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 4));
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 6));
                }
                else
                {
                    #if PRINT
                    cout<<"FLAG 1"<<endl;
                    #endif
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 1));
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 3));
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 5));
                    After_Move_MAP[i][j].push_back(DATA(sum_m, sum_s, 7));
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> m >> s >> d;
        MAP[r-1][c-1].push_back(DATA(m, s, d));
    }
    for (int k = 0; k < K; k++)
    {
        move();
        calc();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                MAP[i][j].clear();
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (After_Move_MAP[i][j].size() != 0)
                {
                    while (!After_Move_MAP[i][j].empty())
                    {
                        int m = After_Move_MAP[i][j].front().m;
                        int s = After_Move_MAP[i][j].front().s;
                        int d = After_Move_MAP[i][j].front().d;
                        MAP[i][j].push_back(DATA(m, s, d));
                        After_Move_MAP[i][j].pop_front();
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j].size() != 0)
            {
                while (!MAP[i][j].empty())
                {
                    int m = MAP[i][j].front().m;
                    answer += m;
                    MAP[i][j].pop_front();
                }
            }
        }
    }
    cout << answer;
}