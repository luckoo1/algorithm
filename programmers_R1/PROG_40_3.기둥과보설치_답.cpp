#include <cstring>
#include <vector>

using namespace std;
bool structure[101][101][2];
int N;

bool canCreate(int x, int y, int type){
    if(type==0){//기둥
        if(y==0||structure[x][y-1][0])return true; //지면 혹은 기둥 존재
        if(x!=0&&structure[x-1][y][1])return true; // 왼 보 
        if(structure[x][y][1])return true; //보
    }else{//보
        if(structure[x][y-1][0]||structure[x+1][y-1][0])return true; //기둥 위
        if(x!=0&&x!=N&&structure[x-1][y][1]&&structure[x+1][y][1])return true; //보 사이
    }
    return false;
}

bool canDelete(int x, int y, int type){
    if(type==0){//기둥
        if(structure[x][y+1][0]&&!canCreate(x,y+1,0)) return false;//위 기둥
        if(structure[x][y+1][1]&&!canCreate(x,y+1,1)) return false;//위 보
        if(x!=0&&structure[x-1][y+1][1]&&!canCreate(x-1,y+1,1)) return false;//위 왼보
    }else{//보
        if(x!=0&&structure[x-1][y][1]&&!canCreate(x-1,y,1)) return false; //왼 보
        if(x!=N&&structure[x+1][y][1]&&!canCreate(x+1,y,1)) return false; //오른 보
        if(y!=N){
            if(structure[x][y][0]&&!canCreate(x,y,0)) return false;//위 기둥
            if(structure[x+1][y][0]&&!canCreate(x+1,y,0)) return false;//위 오른 기둥
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N=n;
    memset(structure,false,sizeof(structure));
    for(vector<int>& frame:build_frame){
        int x=frame[0], y=frame[1], type=frame[2];

        if(frame[3]==0){//삭제
            structure[x][y][type]=false;
            if(!canDelete(x,y,type))
                structure[x][y][type]=true;
        }else{//설치
            if(canCreate(x,y,type))
                structure[x][y][type]=true;
        }
    }

    vector<vector<int>> answer;
    for(int x=0;x<=N;++x)
        for(int y=0;y<=N;++y)
            for(int type=0;type<2;++type)
                if(structure[x][y][type])answer.push_back({x,y,type});

    return answer;
}
