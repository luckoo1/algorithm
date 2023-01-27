/*
비활성바이러스를 지나갈수 있음을 인지하지 못해서 처음에 틀렸다.
처음에 비활성 바이러스를 벽처럼 못지나가게 했었음
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

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
vector<vector<int>> MAP(51, vector<int>(51, 0));
vector<DATA> VIRUS;
vector<DATA> BIN_GONG_GAN;
vector<DATA> ok_virus;
bool check_virus[11];
int N, M;

int answer = 99999999;
int flag = 0;

void PRINT(vector<vector<int>> a)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<a[i][j]<<" ";   
        }
        cout<<endl;
    }
    cout<<endl;
}

void bfs(vector<DATA> ok_virus)
{
    vector<vector<int>> temp_map = MAP;
    vector<vector<bool>> check(N, vector<bool>(N, false));

    queue<DATA> q;

    for (int i = 0; i < VIRUS.size(); i++)
    {
        check[VIRUS[i].r][VIRUS[i].c] = 0;
    }

    for (int i = 0; i < ok_virus.size(); i++)
    {
        temp_map[ok_virus[i].r][ok_virus[i].c] = 0;
        q.push(DATA(ok_virus[i].r, ok_virus[i].c));
        check[ok_virus[i].r][ok_virus[i].c] = true;
    }

    while (!q.empty())
    {
        int now_R = q.front().r;
        int now_C = q.front().c;
        int cnt = temp_map[now_R][now_C];
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int move_R = now_R + DR[k];
            int move_C = now_C + DC[k];
            if (move_R < 0 || move_C < 0 || move_R >= N || move_C >= N)
            {
                continue;
            }
            if (temp_map[move_R][move_C] == 1 || check[move_R][move_C] == true)
            {
                continue;
            }
            
            q.push(DATA(move_R,move_C));
            check[move_R][move_C] = true;
            temp_map[move_R][move_C] = cnt + 1;
        }
    }

    int visited = 0;
    for(int i =0;i<BIN_GONG_GAN.size();i++)
    {
        if(check[BIN_GONG_GAN[i].r][BIN_GONG_GAN[i].c]==true)
        {
            visited+=1;
        }
    }

    if(visited!=BIN_GONG_GAN.size())
    {
        return;
    }

    flag = 1;
    int temp_ans = 0;

    for(int i =0;i<BIN_GONG_GAN.size();i++)
    {
        if(temp_ans < temp_map[BIN_GONG_GAN[i].r][BIN_GONG_GAN[i].c])
        {
            temp_ans = temp_map[BIN_GONG_GAN[i].r][BIN_GONG_GAN[i].c];
        }
    }

    if(answer>temp_ans)
    {
        answer=temp_ans;
    }
    return;
}

void dfs(int k)
{
    if (ok_virus.size() == M)
    {
        bfs(ok_virus);
        return;
    }

    for (int i = k; i < VIRUS.size(); i++)
    {
        if (check_virus[i] == false)
        {
            check_virus[i] = true;
            ok_virus.push_back(DATA(VIRUS[i].r, VIRUS[i].c));
            dfs(i + 1);
            check_virus[i] = false;
            ok_virus.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == 2)
            {
                VIRUS.push_back(DATA(i, j));
            }
            if (MAP[i][j] == 0)
            {
                BIN_GONG_GAN.push_back(DATA(i, j));
            }
        }
    }

    dfs(0);
    if(flag ==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<answer<<endl;
    }
}