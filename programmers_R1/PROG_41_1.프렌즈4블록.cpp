#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt_a(int &m, int &n, vector<vector<bool>>  &check)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] == true)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int m, int n, vector<string> board) // m:세로크기 n:가로크기
{
    int answer = 0;
    while (1)
    {
        vector<vector<bool>> check(m, vector<bool>(n, false));
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                char check_same = board[i][j];
                if (check_same == 'a')
                {
                    continue;
                }
                if (check_same == board[i][j] && check_same == board[i + 1][j] && check_same == board[i][j + 1] && check_same == board[i + 1][j + 1])
                {
                    check[i][j] = true;
                    check[i][j + 1] = true;
                    check[i + 1][j] = true;
                    check[i + 1][j + 1] = true;
                }
            }
        }

        int plus_answer = cnt_a(m, n, check);
        if (plus_answer == 0)
        {
            break;
        }
        answer += plus_answer;

        vector<char> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (check[j][i] != true)
                {
                    temp.push_back(board[j][i]);
                }
            }

            int n = m - temp.size();
            while (n--)
            {
                temp.push_back('a');
            }

            for (int j = m - 1; j >= 0; j--)
            {
                board[j][i] = temp[m - 1 - j];
            }
            temp.clear();
        }
    }

    return answer;
}

int main()
{
    cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;
    cout << solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << endl;
}