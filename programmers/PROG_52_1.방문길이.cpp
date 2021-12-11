#include <string>
#include <set>
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
    set<string> ans;

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

        string dir = "";

        if (dirs[i] == 'R' || dirs[i] == 'U')
        {
            dir += row;
            dir += col;
            dir += next_row;
            dir += next_col;
        }
        else
        {
            dir += next_row;
            dir += next_col;
            dir += row;
            dir += col;
        }
        row = next_row;
        col = next_col;

        ans.insert(dir);
    }

    return ans.size();
}

int main()
{
    string a = "ULURRDLLU";
    string b = "LULLLLLLU";
    string c = "LRLR";
    int ans1 = solution(c);
    cout << ans1 << endl;
}