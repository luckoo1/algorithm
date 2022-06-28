#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<long long> solution(int n, int m, int k, vector<vector<int>> acts) {
    vector<long long> answer;
    map<long long,long long> hash_map;
    vector<vector<long long>> MAP(n,vector<long long>(m,0));

    for(int i=0;i<acts.size();i++)
    {
        int type = acts[i][0];
        int x = acts[i][1]-1;
        int k = acts[i][2];

        if(type==1)
        {
            for(int i=0;i<m;i++)
            {
                if(MAP[x][i]!=k)
                {
                    hash_map[k]++;
                    hash_map[MAP[x][i]]--;
                }
                else
                {
                    MAP[x][i]=k;
                    continue;
                }

                MAP[x][i]=k;
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(MAP[i][x]!=k)
                {
                    hash_map[k]++;
                    hash_map[MAP[i][x]]--;
                }
                else
                {
                    MAP[i][x]=k;
                    continue;
                }

                MAP[i][x]=k;
            }
        }

    }

    vector<long long> vec;
    for(int i=1;i<=k;i++)
    {
        vec.push_back(i);
    }

    for(int i=0;i<k;i++)
    {
        answer.push_back(hash_map[vec[i]]);
    }

    return answer;
}
