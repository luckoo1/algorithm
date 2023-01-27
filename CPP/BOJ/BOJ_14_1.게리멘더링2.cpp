/*★실수포인트*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int answer = 999999999;

vector<vector<int>> MAP(22, vector<int>(22, 0));

void print(vector<vector<int>> a)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void divied( vector<vector<int>> MAP,int r, int c, int d1, int d2)//vector<vector<int>> MAP,
{

    vector<vector<int>> temp_map(N, vector<int>(N, 0));
    //=====================================================
    for (int i = 0; i <= d1; i++)
        temp_map[r + i][c - i] = 5;
    for (int i = 0; i <= d2; i++)
        temp_map[r + i][c + i] = 5;
    for (int i = 0; i <= d2; i++)
        temp_map[r + d1 + i][c - d1 + i] = 5;
    for (int i = 0; i <= d1; i++)
        temp_map[r + d2 + i][c + d2 - i] = 5;
    //=====================================================

    for (int i = 0; i < r + d1; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (temp_map[i][j] == 5)
                break;
            temp_map[i][j] = 1;
        }
    }

    for (int i = 0; i <= r + d2; i++)   /*★d2해야하는걸 d1해서 계속틀림.. */
    {
        for (int j = N - 1; j > c; j--)
        {
            if (temp_map[i][j] == 5)
                break;
            temp_map[i][j] = 2;
        }
    }

    for (int i = r + d1; i < N; i++)
    {
        for (int j = 0; j < c - d1 + d2; j++)
        {
            if (temp_map[i][j] == 5)
                break;
            temp_map[i][j] = 3;
        }
    }

    for (int i = r + d2 + 1; i < N; i++)
    {
        for (int j = N - 1; j >= c + d2 - d1; j--)
        {
            if (temp_map[i][j] == 5)
                break;
            temp_map[i][j] = 4;
        }
    }

    int cnt_one = 0;
    int cnt_two = 0;
    int cnt_three = 0;
    int cnt_four = 0;
    int cnt_five = 0;
    #if 1
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (temp_map[i][j] == 1)
                cnt_one += MAP[i][j];
            if (temp_map[i][j] == 2)
                cnt_two += MAP[i][j];
            if (temp_map[i][j] == 3)
                cnt_three += MAP[i][j];
            if (temp_map[i][j] == 4)
                cnt_four += MAP[i][j];
            if (temp_map[i][j] == 5 || temp_map[i][j] == 0)
                cnt_five += MAP[i][j];
        }
    }
    #endif


    vector<int> cnt;
    cnt.push_back(cnt_one);
    cnt.push_back(cnt_two);
    cnt.push_back(cnt_three);
    cnt.push_back(cnt_four);
    cnt.push_back(cnt_five);
    int min_cnt = *min_element(cnt.begin(), cnt.end());
    int max_cnt = *max_element(cnt.begin(), cnt.end());
    //print(temp_map);
    if (min_cnt == 0)
    {
        return;
    }

    int temp_ans = max_cnt - min_cnt;
    if (temp_ans < answer)
    {
        #if 0
        cout << r << "," << c << "," << d1 << "," << d2 << endl;
        cout<<temp_ans<<endl;
        for(int i=0;i<cnt.size();i++)
        {
            cout<<cnt[i]<< " ";
        }
        cout<<endl;
        print(temp_map);

        #endif
        answer = temp_ans;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int d1 = 1; d1 < N; d1++)
            {
                for (int d2 = 1; d2 < N; d2++)
                {
                    if ((x + d1 + d2) < N)
                    {
                        if ((y - d1) >= 0 && (y + d2) < N)
                        {
                            divied(MAP, x, y, d1, d2);
                        }
                    }
                }
            }
        }
    }

    cout << answer << endl;
}