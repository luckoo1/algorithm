#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 987654321
using namespace std;

struct node{
    int x,y,wall;
    node(int _x,int _y,int _wall) :x(_x),y(_y),wall(_wall){}
};

int n,m;

int map[MAX][MAX];
int dist[MAX][MAX][2];  // [0]: 벽을 부수지 않음, [1]: 벽을 부숨

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(){
    queue<node> q;
    q.push(node(0,0,0));
    dist[0][0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();
        
        if(x==n-1 && y==m-1){
            printf("%d\n",dist[x][y][wall]);
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            
            // 벽이 아니라면
            if(map[nx][ny]==0 && dist[nx][ny][wall] == 0){
                dist[nx][ny][wall] = dist[x][y][wall] + 1;
                q.push(node(nx,ny,wall));
            }
            // 만약 벽을 만나면
            else if(map[nx][ny]==1 && wall==0 && dist[nx][ny][wall+1]==0){
                dist[nx][ny][wall+1] = dist[x][y][wall] + 1;
                q.push(node(nx,ny,wall+1));
            }
        }
    }
    printf("%d\n",-1);
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    scanf("%d %d",&n,&m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
            dist[i][j][0] = 0;
            dist[i][j][1] = 0;
        }
    }
    
    bfs();
}