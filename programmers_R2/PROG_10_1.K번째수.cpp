#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (int i = 0; i < commands.size();i++)
    {
        vector<int> temp_vec{array.begin() + commands[i][0]-1, array.begin() + commands[i][1]};
        sort(temp_vec.begin(), temp_vec.end());
        answer.push_back(temp_vec[commands[i][2]-1]);
    }
    return answer;
}

int main()
{
    vector<int> a{1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> b{{2, 5, 3}, {4, 4, 1}, { 1, 7, 3}};
    vector<int> ans = solution(a, b);
}