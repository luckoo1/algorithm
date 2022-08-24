#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    vector<vector<bool>> check(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int num;
    int temp_ans;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] != 0 && check[i][j] == false)
            {
                num = picture[i][j];
                check[i][j] = true;
                q.push(make_pair(i, j));
                number_of_area += 1;
                temp_ans = 1;
            }

            while (!q.empty())
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    {
                        continue;
                    }
                    if (picture[nr][nc] == num && check[nr][nc] == false)
                    {
                        q.push(make_pair(nr, nc));
                        check[nr][nc] = true;
                        temp_ans += 1;
                    }
                }
            }
            // for(int i=0;i<m;i++)
            // {
            //     for(int j=0;j<n;j++)
            //     {
            //         cout<<check[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            if (temp_ans > max_size_of_one_area)
            {
                max_size_of_one_area = temp_ans;
            }
        }
    }
    vector<int> answer{number_of_area, max_size_of_one_area};

    return answer;
}

int main()
{

    int m = 6; // ROW수
    int n = 4; // COL수
    vector<vector<int>> map{{1, 1, 1, 0},
                            {1, 2, 2, 0},
                            {1, 0, 0, 1},
                            {0, 0, 0, 1},
                            {0, 0, 0, 3},
                            {0, 0, 0, 3}};

    vector<int> ans = solution(m,n,map);
    for(auto n: ans)
    {
        cout<<n<<" ";
    }
}