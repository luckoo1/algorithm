#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    return answer;
}

int main()
{
    cout << solution({{5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5}},
                     {{1, 0, 0, 3, 4, 4},
                      {1, 2, 0, 2, 3, 2},
                      {2, 1, 0, 3, 1, 2},
                      {1, 0, 1, 3, 3, 1}})
         << endl;
    cout << solution({{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}},
                     {{1, 1, 1, 2, 2, 4},
                      {1, 0, 0, 1, 1, 2},
                      {2, 2, 0, 2, 0, 100}})
         << endl;
}