#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;


void print_vec(vector<vector<int>> board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
struct DATA
{
    int r;
    int c;
    int d;
    DATA(int r,int c,int d)
    {
        this->r = r;
        this->c = c;
        this->d = d;
    }
};
int DR[4]={1,-1,0,0};
int DC[4]={0,0,1,-1};
vector<vector<int>> answer;
queue<DATA> q;

int bfs(int x, int y, vector<vector<int>> board,int a_x,int a_y)
{
    int r_size = board.size();
    int c_size = board[0].size();

    vector<vector<int>> diff_map(r_size,vector<int>(c_size,0));
    vector<vector<bool>> check(r_size,vector<bool>(c_size,false));

    q.push(DATA(x,y,0));
    check[x][y]=true;
    int score = board[x][y];

    while(!q.empty())
    {
        int start_r = q.front().r;
        int start_c = q.front().c;
        int start_d = q.front().d;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int move_r = start_r+DR[k];
            int move_c = start_c+DC[k];
            if(move_r<0||move_c<0||move_r >= r_size||move_c >= c_size)
                continue;
            // if(check[move_r][move_c]==true)
            //     continue;
            if(check[move_r][move_c]==true)
            {
                if(board[move_r][move_c] == board[start_r][start_c]){
                    // q.push(DATA(move_r,move_c,start_d));
                    // check[move_r][move_c] = true;
                    if(diff_map[move_r][move_c]>start_d){
                        diff_map[move_r][move_c] = start_d;
                    }
                }
                continue;
            }

            else
            {
                q.push(DATA(move_r,move_c,start_d+1));
                check[move_r][move_c] = true;
                diff_map[move_r][move_c] = start_d+1;   
            }

        }
    }
    // cout<<x<<","<<y<<endl;
    // print_vec(diff_map);

    return diff_map[a_x][a_y];
}
vector<vector<int>> solution(int x, int y, vector<vector<int>> board) {
    int r_size = board.size();
    int c_size = board[0].size();
    vector<vector<int>> diff_map(r_size,vector<int>(c_size,0));
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            diff_map[i][j]= bfs(i, j, board,x-1,y-1);
        }
    }
    map<int,int> hash_map;
    for(int i=0;i<diff_map.size();i++)
    {
        for(int j=0;j<diff_map[0].size();j++)
        {
            hash_map[diff_map[i][j]] +=1;
        }
    }
    int max_num = 0;
    int big_diff = 0;
    print_vec(diff_map);
    for(auto iter = hash_map.begin();iter!=hash_map.end();iter++)
    {
        if(max_num<=iter->second)
        {
            max_num = iter->second;
            big_diff = iter->first;
        }
    }
    for(int i=0;i<diff_map.size();i++)
    {
        for(int j=0;j<diff_map[0].size();j++)
        {
            if(diff_map[i][j]==big_diff)
                answer.push_back({i+1,j+1});
        }
    }
    return answer;
}
/*
5 4 3 4 4 4
1 3 2 3 3 5
2 3 4 5 5 1
2 2 3 4 4 3

14
15
16
26
36
44
45

79797
97979
79797
97979
79797
12
14
21
25
41
45
52
54
*/