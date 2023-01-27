#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> network;

int find_parent(int node)
{
    if (network[node][0] == network[node][1])
    {
        return network[node][1];
    }
    return find_parent(network[node][1]);
}

int solution(int n, vector<vector<int>> computers)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        temp.push_back(i);
        temp.push_back(i);
        network.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (computers[i][j] == 1)
            {
                network[i][1] = j;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        network[i][1] = find_parent(network[i][0]);
    }

    for (int i = 0; i < network.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << network[i][j] << " ";
        }
        cout << "\n";
    }

    bool check[201] = {false};
    for (int i = 0; i < n; i++)
    {
        check[network[i][1]] = true;
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == true)
            answer += 1;
    }

    return answer;
}

int main()
{
    int a = 4;
    vector<vector<int>> b{{1, 1, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 0, 1, 1}}; //틀린예제
    // int a = 7;
    // vector<vector<int>> b{
    //     {1, 1, 1, 0, 0, 0, 0},
    //     {1, 1, 0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 1, 1, 0, 0},
    //     {0, 1, 0, 1, 1, 1, 0},
    //     {0, 0, 0, 0, 1, 1, 0},
    //     {0, 0, 0, 0, 0, 0, 1}};

    int ans = solution(a, b);
    cout << ans;
}

// for (int i = 0; i < network.size(); i++)
// {
//     for (int j = 0; j < 2; j++)
//     {
//         cout << network[i][j] << " ";
//     }
//     cout << "\n";
// }