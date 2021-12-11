#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool map[11][11];
int solution(string dirs)
{
    int row = 0;
    int col = 0;
    int next_row = 0;
    int next_col = 0;

    vector<string> ans;
    for (int i = 0; i < dirs.size(); i++)
    {
        if (dirs[i] == 'L')
        {
            next_row = row;
            next_col = col - 1;
        }
        else if (dirs[i] == 'R')
        {
            next_row = row;
            next_col = col + 1;
        }
        else if (dirs[i] == 'U')
        {
            next_row = row - 1;
            next_col = col;
        }
        else if (dirs[i] == 'D')
        {
            next_row = row + 1;
            next_col = col;
        }

        if (next_row > 5 || next_row < -5 || next_col > 5 || next_col < -5)
            continue;

        string dir = to_string(row) + to_string(col);
        row = next_row;
        col = next_col;
        dir += to_string(row);
        dir += to_string(col);
        sort(dir.begin(), dir.end());
        ans.push_back(dir);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return ans.size();
}

int main()
{
    string a = "ULURRDLLU";
    string b = "LULLLLLLU";
    int ans1 = solution(a);
    cout << ans1 << endl;
}