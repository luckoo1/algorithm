#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    return answer;
}

int main()
{
    vector<vector<int>> a = solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}});
    for (auto n : a)
    {
        for (auto m : n)
        {
            cout << m << " ";
        }
        cout << endl;
    }
    vector<vector<int>> b = solution(5, {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}});
    for (auto n : b)
    {
        for (auto m : n)
        {
            cout << m << " ";
        }
        cout << endl;
    }
}