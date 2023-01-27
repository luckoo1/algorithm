/*
문제를 잘 읽자
물고기는 한 칸을 이동할 수 있고, 
이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸, 
이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.

★물고기는 빈칸을 이동할수 있다!
★void함수가 아니면 무조건 return 값을 넣어야한다.
*/
#include <iostream>
#include <vector>
using namespace std;
#define PRINT 0

int DR[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int DC[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer = 0;
struct FISH
{
    int num;
    int dir;
    FISH(int num, int dir)
    {
        this->num = num;
        this->dir = dir;
    }
};

struct DATA
{
    int r;
    int c;
    DATA(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

void print(vector<vector<FISH>> MAP)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << MAP[i][j].num << " " << MAP[i][j].dir << " ";
        }
        cout << endl;
    }
}

DATA find_fish(vector<vector<FISH>> MAP, int number)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (MAP[i][j].num == number)
            {
                return DATA(i, j);
            }
        }
    }
    return DATA(99, 99);/*★void함수가 아니면 무조건 return 값을 넣어야한다.*/
}

void change_location(vector<vector<FISH>> &MAP, int now_r, int now_c, int move_r, int move_c)
{
    FISH temp = MAP[now_r][now_c];
    MAP[now_r][now_c] = MAP[move_r][move_c];
    MAP[move_r][move_c] = temp;
}

void fish_move(vector<vector<FISH>> &MAP, int now_shark_r, int now_shark_c)
{
    for (int i = 1; i <= 16; i++)
    {
        DATA where_fish = find_fish(MAP, i);
        int now_r = where_fish.r;
        int now_c = where_fish.c;
        if (now_r == 99)
            continue;
        int now_dir = MAP[now_r][now_c].dir;
        for (int k = 0; k < 8; k++)
        {
            int change_dir = (now_dir + k) % 8;
            int move_r = now_r + DR[change_dir];
            int move_c = now_c + DC[change_dir];
            if (move_r < 0 || move_r >= 4 || move_c < 0 || move_c >= 4)
                continue;
            /*★여기를 처음에 (MAP[move_r][move_c].num == 18)로해서 걍 물고기가 죽은곳은 모두 이동못하게 되었다*/
            if (now_shark_r == move_r && now_shark_c == move_c)
                continue;
            MAP[now_r][now_c].dir = change_dir;
            change_location(MAP, now_r, now_c, move_r, move_c);
            break;
        }
    }
}

void dfs(vector<vector<FISH>> MAP, int now_shark_r, int now_shark_c, int now_shark_dir, int temp_ans, int dep)
{
    if (temp_ans > answer)
    {
        answer = temp_ans;
    }
#if PRINT == 1
    cout << "BEFORE_MOVE" << endl;
    cout << temp_ans << "," << now_shark_dir << "," << dep << endl;
    print(MAP);
#endif

    fish_move(MAP, now_shark_r, now_shark_c);

#if PRINT == 1
    cout << "AFTER_MOVE" << endl;
    print(MAP);

#endif
    int move_shark_r = now_shark_r;
    int move_shark_c = now_shark_c;

    for (int i = 1; i <= 16; i++)
    {
        move_shark_r += DR[now_shark_dir];
        move_shark_c += DC[now_shark_dir];

        if (move_shark_r < 0 || move_shark_r >= 4 || move_shark_c < 0 || move_shark_c >= 4)
            break;
        if (MAP[move_shark_r][move_shark_c].num == 18)
            continue;

        int before_num = MAP[move_shark_r][move_shark_c].num;

        int move_shark_dir = MAP[move_shark_r][move_shark_c].dir;
        temp_ans += MAP[move_shark_r][move_shark_c].num;
        MAP[move_shark_r][move_shark_c].num = 18;

#if PRINT == 1
        cout << "AFTER_EAT"
             << " : " << temp_ans << endl;
        print(MAP);
        cout << endl;
#endif

        dfs(MAP, move_shark_r, move_shark_c, move_shark_dir, temp_ans, dep + 1);

        MAP[move_shark_r][move_shark_c].num = before_num;
        temp_ans -= MAP[move_shark_r][move_shark_c].num;
    }
}

int main()
{
    vector<vector<FISH>> MAP(4, vector<FISH>(4, FISH(0, 0)));
    int num;
    int dir;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> num >> dir;
            MAP[i][j] = FISH(num, dir - 1);
        }
    }
    int temp_ans = MAP[0][0].num;
    answer = MAP[0][0].num;
    MAP[0][0].num = 18;
    dfs(MAP, 0, 0, MAP[0][0].dir, temp_ans, 1);

    cout << answer;
}