//BFS
#include <string>
#include <set>
#include <iostream>
using namespace std;
int DR[4]={0,0,-1,1};
int DC[4]={-1,1,0,0};

struct DATA
{
    int nr;
    int nc;
    int mr;
    int mc;
    DATA(int nr,int nc,int mr,int mc)
    {
        this->nr = nr;
        this->nc = nc;
        this->mr = mr;
        this->mr = mc;
    }
};

bool no_graph(int a,int b)
{
    if(a<-5||b<-5||a>5||b>5)
        return true;
    return false;
}

int solution(string dirs) {
    int answer = 0;
    int now_r = 0;
    int now_c = 0;
    set<string> road;
    
    for(int i=0;i<dirs.size();i++)
    {
        if(dirs[i]=='L')
        {
            int move_r = now_r+DR[0];
            int move_c = now_c+DC[0];
            if(no_graph(move_r,move_c))
                continue;
            string str = to_string(now_r)+to_string(now_c)+to_string(move_r)+to_string(move_c);
            road.insert(str);
            str = to_string(move_r)+to_string(move_c)+to_string(now_r)+to_string(now_c);
            road.insert(str);
            now_r = move_r;
            now_c = move_c;
            continue;
        }
        else if(dirs[i]=='R')
        {
            int move_r = now_r+DR[1];
            int move_c = now_c+DC[1];
            if(no_graph(move_r,move_c))
                continue;
            string str = to_string(now_r)+to_string(now_c)+to_string(move_r)+to_string(move_c);
            road.insert(str);
            str = to_string(move_r)+to_string(move_c)+to_string(now_r)+to_string(now_c);
            road.insert(str);
            now_r = move_r;
            now_c = move_c;
            continue;
        }
        else if(dirs[i]=='U')
        {
            int move_r = now_r+DR[2];
            int move_c = now_c+DC[2];
            if(no_graph(move_r,move_c))
                continue;
            string str = to_string(now_r)+to_string(now_c)+to_string(move_r)+to_string(move_c);
            road.insert(str);
            str = to_string(move_r)+to_string(move_c)+to_string(now_r)+to_string(now_c);
            road.insert(str);
            now_r = move_r;
            now_c = move_c;
            continue;
        }
        else if(dirs[i]=='D')
        {
            int move_r = now_r+DR[3];
            int move_c = now_c+DC[3];
            if(no_graph(move_r,move_c))
                continue;
            string str = to_string(now_r)+to_string(now_c)+to_string(move_r)+to_string(move_c);
            road.insert(str);
            str = to_string(move_r)+to_string(move_c)+to_string(now_r)+to_string(now_c);
            road.insert(str);
            now_r = move_r;
            now_c = move_c;
            continue;
        }
    }
    
    answer = road.size()/2;
    return answer;
}

int main()
{
    cout<<solution("ULURRDLLU")<<endl;
    cout<<solution("LULLLLLLU")<<endl;
}