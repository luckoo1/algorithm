/*
        int zero_cnt = -1;  /*이거때문에 런타임 에러가 계속 발생했다.
*/
#include <iostream>
#include <vector>
using namespace std;

struct DATA
{
    int r;
    int c;
    DATA(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

void print(vector<vector<int>> a)
{
    cout << "PRINT" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int N;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int calc_zero(int r, int c, vector<vector<int>> MAP)
{
    int cnt = 0;

    vector<int> retr_vec;
    int temp_cnt = 0;
    for (int k = 0; k < 4; k++)
    {
        int move_DR = r + dr[k];
        int move_DC = c + dc[k];
        if (move_DR < 0 || move_DC < 0 || move_DR >= N || move_DC >= N)
            continue;
        if (MAP[move_DR][move_DC] == 0)
        {
            temp_cnt++;
        }
        if (temp_cnt > cnt)
        {
            cnt = temp_cnt;
            retr_vec.clear();
            retr_vec.push_back(r);
            retr_vec.push_back(c);
        }
    }
    return cnt;
}

int calc(int r, int c, vector<int> like, vector<vector<int>> MAP)
{
    int cnt = 0;
    for (int k = 0; k < 4; k++)
    {
        int move_DR = r + dr[k];
        int move_DC = c + dc[k];
        if (move_DR < 0 || move_DC < 0 || move_DR >= N || move_DC >= N)
            continue;
        if (MAP[move_DR][move_DC] == 0)
            continue;
        for (int i = 1; i < like.size(); i++)
        {
            if (like[i] == MAP[move_DR][move_DC])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> N;
    vector<vector<int>> MAP(N, vector<int>(N, 0));
    vector<vector<int>> LIKE;
    int num;
    vector<int> temp;
    for (int i = 0; i < N * N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> num;
            temp.push_back(num);
        }
        LIKE.push_back(temp);
        temp.clear();
    }

    for (int k = 0; k < N * N - 1; k++)
    {
        //print(MAP);
        int like_cnt = 0;
        int row = -1;
        int col = -1;
        int same_like = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAP[i][j] != 0)
                {
                    continue;
                }
                int temp_like_cnt = calc(i, j, LIKE[k], MAP);
                if (temp_like_cnt > like_cnt)
                {
                    like_cnt = temp_like_cnt;
                    row = i;
                    col = j;
                    same_like = 0;
                }
                if (temp_like_cnt == like_cnt)
                {
                    same_like += 1;
                }
            }
        }
        vector<DATA> temp_ans;
        if (same_like > 1)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (MAP[i][j] != 0)
                    {
                        continue;
                    }
                    int temp_like_cnt = calc(i, j, LIKE[k], MAP);
                    if (temp_like_cnt == like_cnt)
                    {
                        temp_ans.push_back(DATA(i, j));
                    }
                }
            }
            int max_cnt = 0;
            for (int i = 0; i < temp_ans.size(); i++)
            {
                int temp_cnt = calc_zero(temp_ans[i].r, temp_ans[i].c, MAP);
                if (temp_cnt > max_cnt)
                {
                    max_cnt = temp_cnt;
                    row = temp_ans[i].r;
                    col = temp_ans[i].c;
                }
            }
        }

        temp_ans.clear();

        if (row != -1 & col != -1)
        {
            MAP[row][col] = LIKE[k][0];
            continue;
        }
        int zero_cnt = -1;  /*이거때문에 런타임 에러가 계속 발생했다.*/
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAP[i][j] != 0)
                {
                    continue;
                }
                int temp_zero_cnt = calc_zero(i, j, MAP);
                if (temp_zero_cnt > zero_cnt)
                {
                    zero_cnt = temp_zero_cnt;
                    row = i;
                    col = j;
                    same_like = 0;
                }
            }
        }
        MAP[row][col] = LIKE[k][0];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == 0)
            {
                MAP[i][j] = LIKE[N * N - 1][0];
                break;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < LIKE.size(); k++)
            {
                if (MAP[i][j] == LIKE[k][0])
                {
                    int like_ans = calc(i, j, LIKE[k], MAP);
                    if (like_ans == 1)
                    {
                        answer += 1;
                    }
                    else if (like_ans == 2)
                    {
                        answer += 10;
                    }
                    else if (like_ans == 3)
                    {
                        answer += 100;
                    }
                    else if (like_ans == 4)
                    {
                        answer += 1000;
                    }
                }
            }
        }
    }
    cout << answer;
}