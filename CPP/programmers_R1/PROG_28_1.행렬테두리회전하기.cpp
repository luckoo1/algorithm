#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print_map(vector<vector<int>> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int find_min(vector<vector<int>> map, vector<int> queries)
{
    vector<int> num;
    int up_row = queries[0] - 1;
    int up_col = queries[1] - 1;
    int low_row = queries[2] - 1;
    int low_col = queries[3] - 1;

    for (int i = up_col; i <= low_col; i++) //가로줄 다 넣기
    {
        num.push_back(map[up_row][i]);
        num.push_back(map[low_row][i]);
    }
    for (int i = up_row + 1; i < low_row; i++) //세로줄 다 넣기(모서리 부분은 제외)
    {
        num.push_back(map[i][up_col]);
        num.push_back(map[i][low_col]);
    }
    return *min_element(num.begin(), num.end());
}

vector<vector<int>> rotate(vector<vector<int>> map, vector<int> queries)
{
    vector<vector<int>> temp_map = map;
    int up_row = queries[0] - 1;
    int up_col = queries[1] - 1;
    int low_row = queries[2] - 1;
    int low_col = queries[3] - 1;

    for (int i = up_col; i < low_col; i++)
    {
        temp_map[up_row][i + 1] = map[up_row][i];
    }
    for (int i = up_row; i < low_row; i++)
    {
        temp_map[i + 1][low_col] = map[i][low_col];
    }
    for (int i = up_col; i < low_col; i++)
    {
        temp_map[low_row][i] = map[low_row][i + 1];
    }
    for (int i = up_row; i < low_row; i++)
    {
        temp_map[i][up_col] = map[i + 1][up_col];
    }
    return temp_map;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> ans;
    vector<vector<int>> map(rows, vector<int>(columns, 0));
    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            map[i][j] = num;
            num+=1;
        }
    }
    for (auto n : queries)
    {
        ans.push_back(find_min(map, n)); //돌리기 전에 최소값 넣기
        map = rotate(map, n);            //돌리기
    }
    return ans;
}

int main()
{
    vector<int> a(solution(6, 6, {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}));
    //vector<int> b(solution(3, 3, {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}}));
    //  vector<int> c( solution(100, 97, {{1, 1, 100, 97}}));
}
