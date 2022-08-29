#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void PRINT(vector<vector<int>> MAP)
{
    for(int i=0;i<MAP.size();i++)
    {
        for(int j=0;j<MAP[i].size();j++)
        {
            cout<<MAP[i][j]<<" ";
        }
        cout<<endl;
    }
}
struct DATA
{
    int r;
    int c;
    int wall_erase;
    DATA(int r,int c,int wall_erase)
    {
        this->r = r;
        this->c = c;
        this->wall_erase = wall_erase;
    }
};

int N,M;
int DR[4]={1,-1,0,0};
int DC[4]={0,0,1,-1};
int bfs(vector<vector<int>> &MAP,vector<vector<bool>> &check)
{
    queue<DATA> q;
    vector<vector<int>> dist(N,vector<int>(M,0));
    q.push(DATA(0,0,1));
    check[0][0]=true;
    while(!q.empty())
    {
        int start_R = q.front().r;
        int start_C = q.front().c;
        int start_Wall_erase = q.front().wall_erase;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int move_R = start_R + DR[k];
            int move_C = start_C + DC[k];
            if(move_R>=N||move_R<0||move_C>=M||move_C<0)
                continue;

            if(MAP[move_R][move_C] == 0 && check[move_R][move_C] == false)
            {
                q.push(DATA(move_R,move_C,start_Wall_erase));
                check[move_R][move_C] = true;
                dist[move_R][move_C] = dist[start_R][start_C]+1;
                continue;
            }
            if(MAP[move_R][move_C] == 1 && start_Wall_erase == 1)
            {
                q.push(DATA(move_R,move_C,0));
                check[move_R][move_C] = true;
                dist[move_R][move_C] = dist[start_R][start_C]+1;
                continue;
            }
        }
    }
    // dist[start_R][start_C]+1 >= dist[move_R][move_C]
    PRINT(MAP);
    cout<<endl;
    PRINT(dist);
    return dist[N-1][M-1];

}


int main()
{
    freopen("Input.txt","r",stdin);
    cin>>N>>M;
    vector<vector<int>> MAP(N,vector<int>(M,0));
    vector<vector<bool>> check(N,vector<bool>(M,false));
    int num;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%1d",&num);
            MAP[i][j]=num;
        }
    }
    int ans = bfs(MAP,check);
    
    if(check[N-1][M-1] == 0)
    {
        ans = -1;
    }
    else
    {
        if(ans!=0)
            ans = ans + 1;
    }
    cout<<ans;


}