//62번줄때문에 틀림
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int rotate(int idx, vector<vector<int>> &map, vector<vector<int>> &queries)
{
    int left_col = queries[idx][1] - 1;
    int right_col = queries[idx][3] - 1;
    int upper_row = queries[idx][0] - 1;
    int lower_row = queries[idx][2] - 1;

    //회전
    int temp = map[upper_row][right_col];
    //맨위쪽이 오른쪽에서 왼쪽으로
    for (int i = right_col; i > left_col; i--)
    {
        map[upper_row][i] = map[upper_row][i - 1];
    }

    //맨왼쪽이 아래에서 위로
    for (int i = upper_row; i < lower_row; i++)
    {
        map[i][left_col] = map[i + 1][left_col];
    }

    //맨아래쪽이 오른쪽에서 왼쪽으로
    for (int i = left_col; i < right_col; i++)
    {
        map[lower_row][i] = map[lower_row][i + 1];
    }

    //맨오른쪽이 위쪽에서 아래쪽으로

    for (int i = lower_row; i > upper_row + 1; i--)
    {
        map[i][right_col] = map[i - 1][right_col];
    }

    map[upper_row + 1][right_col] = temp;

    //최소값 구하기
    int temp_min = 99999999;
    //맨위쪽 왼쪽에서 오른쪽으로 탐색
    for (int i = left_col; i <= right_col; i++)
    {
        if (temp_min > map[upper_row][i])
        {
            temp_min = map[upper_row][i];
        }
    }
    //맨아래쪽 왼쪽에서 오른쪽으로 탐색
    for (int i = left_col; i <= right_col; i++)
    {
        if (temp_min > map[lower_row][i])
        {
            temp_min = map[lower_row][i];
        }
    }
    //맨왼쪽 위에서 아래로 탐색
    for (int i = upper_row; i <= lower_row; i++) //for (int i = upper_row; i <= upper_row; i++)라고 써서 틀림;;
    {
        if (temp_min > map[i][left_col])
        {
            temp_min = map[i][left_col];
        }
    }
    //맨오른쪽 위에서 아래로 탐색
    for (int i = upper_row; i <= lower_row; i++)
    {
        if (temp_min > map[i][right_col])
        {
            temp_min = map[i][right_col];
        }
    }

    return temp_min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<vector<int>> vec(rows, vector<int>(columns));
    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            vec[i][j] = num;
            num += 1;
        }
    }

    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        ans.push_back(rotate(i, vec, queries));
    }
    return ans;
}

int main()
{
    int a = 6;
    int b = 6;
    vector<vector<int>> c{{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}};
    vector<vector<int>> d{{1, 1, 3, 3}};
    vector<int> ans = solution(a, b, c);
}
