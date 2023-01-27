#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int d_row[4] = {1, -1, 0, 0};
    int d_col[4] = {0, 0, 1, -1};
    int max_row = maps.size();
    int max_col = maps[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> dist(max_row, vector<int>(max_col, 0));
    vector<vector<bool>> visited(max_row, vector<bool>(max_col, 0));

    q.push(make_pair(0, 0));
    dist[0][0] = 1;
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        visited[row][col] = true;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int moved_row = row + d_row[k];
            int moved_col = col + d_col[k];
            if (moved_row < 0 || moved_col < 0 || moved_row >= max_row || moved_col >= max_col)
                continue;
            if (visited[moved_row][moved_col] == true)
                continue;
            if (maps[moved_row][moved_col] == 0)
                continue;

            q.push(make_pair(moved_row, moved_col));
            dist[moved_row][moved_col] = dist[row][col] + 1;
            visited[moved_row][moved_col] = true;
        }
    }

    int answer = dist[max_row - 1][max_col - 1];
    if (answer == 0)
        return -1;
    return answer;
}

int main()
{
    vector<vector<int>> a{{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    int ans = solution(a);
    cout << ans << endl;
}