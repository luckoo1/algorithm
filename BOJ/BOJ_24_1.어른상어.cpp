#include <iostream>
#include <vector>
using namespace std;

int DR[4]={-1,1,0,0};
int DC[4]={0,0,-1,1};
/*위,아래,왼,오*/
int N,M,K;
int main()
{
    cin>>N>>M>>K;
    vector<vector<int>> MAP(N,vector<int> (N,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>MAP[i][j];
        }
    }
    int init_num;
    vector<int> NOW_DIR;
    for(int i=0;i<M;i++)
    {
        cin>>init_num;
        NOW_DIR.push_back(init_num);
    }
    vector<vector<vector<int>>> MOVE_DIR(M,vector<vector<int>>(4,vector<int>(4,0)));
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                cin>>init_num;
                MOVE_DIR[i][j][k] = init_num;
            }
        }
    }


}