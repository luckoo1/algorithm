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

int ABS(int a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}

void MOVE_SHARK(vector<vector<int>> &SHARK)
{
    vector<vector<DATA>> MAP(R + 1, vector<DATA>(C + 1, DATA(0, 0, 0, 0, 0)));
    vector<vector<int>> SIZE_MAP(R + 1, vector<int>(C + 1, 0));

    for (int i = 0; i < SHARK.size(); i++)
    {
        int now_R = SHARK[i][0] - 1;
        int now_C = SHARK[i][1] - 1;
        int speed = SHARK[i][2];
        int dir = SHARK[i][3];
        int size = SHARK[i][4];
        /*1:위 2:아래 3:오른 4:왼*/

        int move_R = (ABS(now_R + (DR[dir] * speed))) % (R - 1);
        int move_C = (ABS(now_C + (DC[dir] * speed))) % (C - 1);

        int check_R = ((ABS(now_R + (DR[dir] * speed))) / (R - 1)) / 2;
        int check_C = ((ABS(now_C + (DC[dir] * speed))) / (C - 1)) / 2;

        if (dir == 1)
        {
            if (check_C == 0)
            {
                move_C = (C - 1) - move_C;
            }
            move_R = now_R;
        }
        if (dir == 2)
        {
            if (check_C == 1)
            {
                move_C = (C - 1) - move_C;
            }
            move_R = now_R;
        }
        if (dir == 3)
        {
            if (check_R == 1)
            {
                move_R = (R - 1) - move_R;
            }
            move_R = now_R;
        }
        if (dir == 4)
        {
            if (check_R == 0)
            {
                move_R = (R - 1) - move_R;
            }
            move_R = now_R;
        }

        if (SIZE_MAP[move_R + 1][move_C + 1] > 0)
        {
            if (MAP[move_R + 1][move_C + 1].size < size)
            {
                MAP[move_R + 1][move_C + 1].r = move_R;
                MAP[move_R + 1][move_C + 1].c = move_C;
                MAP[move_R + 1][move_C + 1].speed = speed;
                MAP[move_R + 1][move_C + 1].dir = dir;
                MAP[move_R + 1][move_C + 1].size = size;
            }
        }
        else
        {
            MAP[move_R + 1][move_C + 1].r = move_R;
            MAP[move_R + 1][move_C + 1].c = move_C;
            MAP[move_R + 1][move_C + 1].speed = speed;
            MAP[move_R + 1][move_C + 1].dir = dir;
            MAP[move_R + 1][move_C + 1].size = size;
            SIZE_MAP[move_R + 1][move_C + 1] = size;
        }
    }
    SHARK.clear();
    vector<int> temp;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            temp.clear();
            if(SIZE_MAP[i][j]>0)
            {
                temp.push_back(MAP[i][j].r);
                temp.push_back(MAP[i][j].c);
                temp.push_back(MAP[i][j].speed);
                temp.push_back(MAP[i][j].dir);
                temp.push_back(MAP[i][j].size);
            }
            if(temp.size()>0)
            {
                SHARK.push_back(temp);
            }
        }
    }

    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cout<<SIZE_MAP[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
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
        if (shark_row != 999)
        {
            answer += SHARK[get_shark_idx][4];
            SHARK.erase(SHARK.begin() + get_shark_idx);
        }

        MOVE_SHARK(SHARK);
    }

    cout << answer;
}