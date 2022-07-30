/*
"★여기가 핵심"보기
단순히 모듈러를 통해 돌아오는 지점만 파악한뒤에 for문으로 이동시켰다.
*/
#include <iostream>
#include <vector>
using namespace std;

int R, C, K;
int DR[5] = {0, -1, 1, 0, 0};
int DC[5] = {0, 0, 0, 1, -1};

struct DATA
{
    int r;
    int c;
    int speed;
    int dir;
    int size;
    DATA(int r, int c, int speed, int dir, int size)
    {
        this->r = r;
        this->c = c;
        this->speed = speed;
        this->dir = dir;
        this->size = size;
    }
};

void MOVE_SHARK(vector<vector<int>> &SHARK)
{
    vector<vector<int>> SIZE_MAP(R + 1, vector<int>(C + 1, 0));
    vector<vector<DATA>> MAP(R + 1, vector<DATA>(C + 1, DATA(0, 0, 0, 0, 0)));

    for (int i = 0; i < SHARK.size(); i++)
    {
        int ROW = SHARK[i][0];
        int COL = SHARK[i][1];
        int speed = SHARK[i][2];
        int dir = SHARK[i][3];
        int size = SHARK[i][4];
        /*1:위 2:아래 3:오른 4:왼*/
        /*상어 이동시키기*/
        if (dir == 1 || dir == 2)
        {
            int move = speed % ((R - 1) * 2);/*★여기가 핵심*/
            for (int i = 1; i <= move; i++)
            {
                if (ROW == R)
                {
                    dir = 1;
                }
                else if (ROW == 1)
                {
                    dir = 2;
                }
                ROW = ROW + DR[dir];
            }
        }
        else if (dir == 3 || dir == 4)
        {
            int move = speed % ((C - 1) * 2);/*★여기가 핵심*/
            for (int i = 1; i <= move; i++)
            {
                if (COL == C)
                {
                    dir = 4;
                }
                else if (COL == 1)
                {
                    dir = 3;
                }
                COL = COL + DC[dir];
            }
        }
        /*사이즈가 작은상어 erase하기*/
        if (SIZE_MAP[ROW][COL] > 0)
        {
            if (SIZE_MAP[ROW][COL] < size)
            {
                SIZE_MAP[ROW][COL] = size;
                MAP[ROW][COL].r = ROW;
                MAP[ROW][COL].c = COL;
                MAP[ROW][COL].speed = speed;
                MAP[ROW][COL].dir = dir;
                MAP[ROW][COL].size = size;
            }
        }
        else
        {
            SIZE_MAP[ROW][COL] = size;
            MAP[ROW][COL].r = ROW;
            MAP[ROW][COL].c = COL;
            MAP[ROW][COL].speed = speed;
            MAP[ROW][COL].dir = dir;
            MAP[ROW][COL].size = size;
        }
    }
    /*SHARK 재정의*/
    SHARK.clear();
    vector<int> temp;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (SIZE_MAP[i][j] != 0)
            {
                temp.push_back(MAP[i][j].r);
                temp.push_back(MAP[i][j].c);
                temp.push_back(MAP[i][j].speed);
                temp.push_back(MAP[i][j].dir);
                temp.push_back(MAP[i][j].size);
                SHARK.push_back(temp);
            }
            temp.clear();
        }
    }
}

int main()
{
    cin >> R >> C >> K;
    vector<vector<int>> SHARK(K, vector<int>(5, 0));
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> SHARK[i][j];
        }
    }

    int answer = 0;
    /*낚시되는 상어 정하기*/
    for (int PERSON = 1; PERSON <= C; PERSON++)
    {
        int shark_row = 999;
        int get_shark_idx = 0;
        for (int SHARK_idx = 0; SHARK_idx < SHARK.size(); SHARK_idx++)
        {
            if (SHARK[SHARK_idx][1] == PERSON)
            {
                if (shark_row > SHARK[SHARK_idx][0])
                {
                    get_shark_idx = SHARK_idx;
                    shark_row = SHARK[SHARK_idx][0];
                }
            }
        }
        /*낚시한 상어 erase하기*/
        if (shark_row != 999)
        {
            answer += SHARK[get_shark_idx][4];
            SHARK.erase(SHARK.begin() + get_shark_idx);
        }
        /*상어이동*/
        MOVE_SHARK(SHARK);
    }

    cout << answer;
}