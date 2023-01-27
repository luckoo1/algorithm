#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

void print(vector<vector<int>> a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

struct DATA
{
    int r;
    int c;
    int cnt;
    DATA(int r,int c,int cnt)
    {
        this->r = r;
        this->c =c;
        this->cnt = cnt;
    }
};
int bfs(vector<string> maze)
{
    vector<vector<bool>> check(maze.size(),vector<bool> (maze.size(),false));
    vector<vector<int>> ans(maze.size(),vector<int> (maze.size(),0));
    queue<DATA> q;
    q.push(DATA(maze.size()-1,0,0));
    check[0][0]=true;
    while(!q.empty())
    {
        int start_r = q.front().r;
        int start_c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();
        check[start_r][start_c] = true;
        for(int k=0;k<4;k++)
        {
            int move_r = start_r+dr[k];
            int move_c = start_c+dc[k];
            if(move_r<0||move_c<0||move_r>=maze.size()||move_c>=maze.size())
            {
                continue;
            }
            if(check[move_r][move_c]==true||maze[move_r][move_c]=='#')
            {
                continue;
            }

            q.push(DATA(move_r,move_c,cnt+1));
            check[move_r][move_c] = true;
            ans[move_r][move_c]=cnt+1;

            // q.push(DATA(move_r,move_c,cnt+1));
            // check[move_r][move_c] = true;
            // ans[move_r][move_c]=cnt+1;


            // if(ans[move_r][move_c]>cnt+2)
            // {
            //     if(maze[move_c][move_r]!='#'&&check[move_c][move_r]==false)
            //     {
            //         q.push(DATA(move_c,move_r,cnt+2));
            //         check[move_c][move_r] = true;
            //     }
            //     ans[move_r][move_c]=cnt+2;
            // }


        }
    }
    
    return ans[0][maze.size()-1];
}

int solution(vector<string> maze) {
    int answer = bfs(maze);
    if(answer==0)
    {
        return -1;
    }
    return answer;
}
