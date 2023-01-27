#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[1001][1001];
vector<int> solution(int n)
{
    int row = 0;
    int col = 0;
    int state = 0;
    int num = 1;

    for (int i = 0; i < n; i++)
    {
        if (state == 0)
        {
            for (int j = i; j < n; j++)
                arr[row++][col] = num++;
            row -= 1;
            col += 1;
            state = 1;
        }
        else if (state == 1)
        {
            for (int j = i; j < n; j++)
                arr[row][col++] = num++;
            row -= 1;
            col -= 2;
            state = 2;
        }
        else if (state == 2)
        {
            for (int j = i; j < n; j++)
                arr[row--][col--] = num++;
            row += 2;
            col += 1;
            state = 0;
        }
    }
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}
