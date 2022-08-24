#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> cut_vec;
    for (int i = 0; i < commands.size(); i++)
    {
        int start = commands[i][0] - 1;
        int finish = commands[i][1];
        int idx = commands[i][2];

        for (int j = start; j < finish; j++)
        {
            cut_vec.push_back(array[j]);
        }

        sort(cut_vec.begin(), cut_vec.end());

        cout << endl;
        answer.push_back(cut_vec[idx - 1]);
        cut_vec.clear();
    }
    return answer;
}

int main()
{
    vector<int> a1{1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> b1{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> ans = solution(a1, b1);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}