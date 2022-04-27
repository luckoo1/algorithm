#include <vector>
#include <iostream>
using namespace std;
#define MOD 1000000007


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(n,vector<int>(m,1));

    for(int i=0;i<puddles.size();i++)
    {
        map[puddles[i][0]-1][puddles[i][1]-1] = -1;
    }



    return answer;
}

    // for(int i=0;i<map.size();i++)
    // {
    //     for(int j=0;j<map[i].size();j++)
    //     {
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }