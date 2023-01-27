#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void PRINT_MAP(vector<string> MAP)
{
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

struct DATA
{
    int r;
    int c;
    int type;
    int cnt;
    DATA(int r, int c, int type, int cnt)
    {
        this->r = r;
        this->c = c;
        this->type = type;
        this->cnt = cnt;
    }
};

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

void bfs(int N, int M)
{
    string MAP_info;
    vector<string> MAP;
    queue<DATA> q;
    for (int i = 0; i < N; i++)
    {
        cin >> MAP_info;
        MAP.push_back(MAP_info);
    }

    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] == '*')
            {
                q.push(DATA(i, j, 0, 0));
            }
        }
    }
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] == '@')
            {
                q.push(DATA(i, j, 1, 0));
            }
        }
    }


    while (!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int type = q.front().type;
        int cnt = q.front().cnt;
        q.pop();
        //cout << r << "," << c << "," << type << ","<<cnt<<endl;

        if (type == 0) /*불*/
        {
            for (int k = 0; k < 4; k++)
            {
                int MR = r + DR[k];
                int MC = c + DC[k];
                if (MR < 0 || MC < 0 || MR >= N || MC >= M)
                    continue;
                if(MAP[MR][MC]=='#'||MAP[MR][MC]=='*')
                    continue;
                q.push(DATA(MR,MC,type,0));
                MAP[MR][MC]='*';
            }
        }
        else if(type == 1)
        {
            for (int k = 0; k < 4; k++)
            {
                int MR = r + DR[k];
                int MC = c + DC[k];
                if (MR < 0 || MC < 0 || MR >= N || MC >= M)
                {
                    cout<<cnt+1<<endl;
                    return;
                }
                if(MAP[MR][MC]=='#'||MAP[MR][MC]=='*')
                    continue;
                q.push(DATA(MR,MC,type,cnt+1));
                MAP[MR][MC]='@';
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    //freopen("Input.txt", "r", stdin);
    int CNT;
    int M, N;
    cin>> CNT;
    while(CNT--){
        cin >> M >> N;
        bfs(N, M);
    }
}
