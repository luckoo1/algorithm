#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
vector<vector<int>> MAP(22, vector<int>(22, 0));
vector<vector<int>> SCORE(22, vector<int>(22, 0));
vector<vector<bool>> g_check(22, vector<bool>(22, false));
vector<int> dice{2, 1, 5, 6, 4, 3};

int DR[4] = {0, -1, 0, 1};
int DC[4] = {1, 0, -1, 0};

void PRINT_VEC(vector<vector<int>> vec)
{
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

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

vector<int> rotate_left()
{
    vector<int> temp = dice;
    temp[1] = dice[5];
    temp[3] = dice[4];
    temp[4] = dice[1];
    temp[5] = dice[3];
    return temp;
}
vector<int> rotate_right()
{
    vector<int> temp = dice;
    temp[1] = dice[4];
    temp[3] = dice[5];
    temp[4] = dice[3];
    temp[5] = dice[1];
    return temp;
}
vector<int> rotate_up()
{
    vector<int> temp = dice;
    temp[0] = dice[1];
    temp[1] = dice[2];
    temp[2] = dice[3];
    temp[3] = dice[0];
    return temp;
}
vector<int> rotate_down()
{
    vector<int> temp = dice;
    temp[0] = dice[3];
    temp[1] = dice[0];
    temp[2] = dice[1];
    temp[3] = dice[2];
    return temp;
}

void bfs(int r, int c)
{
    vector<vector<bool>> visited(22, vector<bool>(22, false));

    queue<DATA> q;
    q.push(DATA(r, c));
    g_check[r][c] = true;
    visited[r][c] = true;

    int number = SCORE[r][c];
    int cnt = 1;

    while (!q.empty())
    {
        int start_R = q.front().r;
        int start_C = q.front().c;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_R = start_R + DR[k];
            int move_C = start_C + DC[k];

            if (move_R < 1 || move_C < 1 || move_R > N || move_C > M)
                continue;
            if (g_check[move_R][move_C] == true)
                continue;
            if (SCORE[move_R][move_C] != number)
                continue;

            q.push(DATA(move_R, move_C));
            g_check[move_R][move_C] = true;
            visited[move_R][move_C] = true;
            cnt += 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (visited[i][j] == true)
            {
                SCORE[i][j] = SCORE[i][j] * cnt;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
        }
    }

    SCORE = MAP;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (g_check[i][j] == false)
            {
                bfs(i, j);
            }
        }
    }

    /*오른쪽,위쪽,왼쪽,아래쪽*/
    int answer = 0;
    int MOVE_R = 1;
    int MOVE_C = 1;
    int dir = 0;
    while (K--)
    {
        /*이동*/
        MOVE_R = MOVE_R + DR[dir];
        MOVE_C = MOVE_C + DC[dir];

        if (MOVE_R < 1 || MOVE_C < 1 || MOVE_R > N || MOVE_C > M)
        {
            MOVE_R = MOVE_R - DR[dir];
            MOVE_C = MOVE_C - DC[dir];
            dir = (dir + 2) % 4;
            MOVE_R = MOVE_R + DR[dir];
            MOVE_C = MOVE_C + DC[dir];
        }

        /*주사위 돌리기*/
        if(dir == 0)
        {
            dice = rotate_right();
        }
        else if(dir ==1)
        {
            dice = rotate_up();
        }
        else if(dir ==2)
        {
            dice = rotate_left();
        }
        else if(dir ==3)
        {
            dice = rotate_down();
        }

        answer+=SCORE[MOVE_R][MOVE_C];
        // cout<<dir<<"  "<<MOVE_R<<","<<MOVE_C<<endl;
        // for(auto n: dice)
        // {
        //     cout<<n<<" ";
        // }
        // cout<<endl;
        /*다음 방향 판단*/
        if(dice[3]>MAP[MOVE_R][MOVE_C])
        {
            dir = (dir+3)%4;
        }
        else if(dice[3]<MAP[MOVE_R][MOVE_C])
        {
            dir = (dir+1)%4;
        }  
        // cout<<dir<<","<<answer<<endl;
        // cout<<endl;
    }
    cout<<answer;
}