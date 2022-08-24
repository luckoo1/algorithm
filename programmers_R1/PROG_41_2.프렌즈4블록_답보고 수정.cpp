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
        int flag =0;
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
                    flag = 1;
                }
            }
        }
        

        if (flag == 0)
            break;
        
        /*
        check true된것을 맨위까지 올리고 'a'로 처리
        check true된것들은 한칸씩 내려오는 IDEA
        */
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check[i][j]==true)
                {
                    answer++;
                    for(int k=i;k>0;k--)
                    {
                        board[k][j]=board[k-1][j];
                    }
                    board[0][j] ='a';
                }
            }
        }

    }

    return answer;
}

int main()
{
    cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;
    cout << solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << endl;
}