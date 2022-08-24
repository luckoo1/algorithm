#include <iostream>
#include <string>
#include <vector>
using namespace std;

int check[201];
void dfs(const int &n, const int &node, vector<vector<int>> map)
{
    for (int i = 0; i < n; i++)
    {
        if(node == i)
        {
            continue;
        }

        if (map[node][i] == 1 && check[i] == false)
        {
            check[i] = true;
            dfs(n, i, map);
        }
    }

    return;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            dfs(n, i, computers);
            answer += 1;
        }
    }

    return answer;
}

int main()
{
    cout <<"ANSWER : "<< solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}})<<endl;
    for(int i=0;i<201;i++)
    {
        check[i]=false;
    }
    cout << "ANSWER : "<< solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}})<<endl;
}