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

vector<int> calc_same_like_zero(vector<DATA> like,vector<vector<int>> MAP)
{
    int cnt = 0;
    int row;
    int col;
    vector<int> retr_vec;
    for (int i = 0; i < like.size(); i++)
    {
        int row = like[i].r;
        int col = like[i].c;
        int temp_cnt = 0;
        for (int k = 0; k < 4; k++)
        {
            int move_DR = row + dr[k];
            int move_DC = col + dc[k];
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
                retr_vec.push_back(row);
                retr_vec.push_back(row);
            }
        }
    }
    return retr_vec;
}

vector<int> calc_zero(vector<vector<int>> MAP)
{
    int cnt = 0;
    int row;
    int col;
    vector<int> retr_vec;
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] != 0)
                continue;
            int temp_cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int move_DR = i + dr[k];
                int move_DC = j + dc[k];
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
                    retr_vec.push_back(i);
                    retr_vec.push_back(j);
                }
            }
        }
    }
    return retr_vec;
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
    vector<DATA> temp_ans;
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

    for (int k = 0; k < N * N; k++)
    {

        int like_cnt = 0;
        int row = -1;
        int col = -1;
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
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAP[i][j] != 0)
                {
                    continue;
                }
                if (like_cnt == calc(i, j, LIKE[k], MAP))
                {
                    flag+=1;
                    temp_ans.push_back(DATA(i,j));
                }
            }
        }
        if(flag>1){
        vector<int> temp_vec = calc_same_like_zero(temp_ans,MAP);
        row = temp_vec[0];
        col = temp_vec[1];
        MAP[row][col] = LIKE[k][0];
        }
        else
        {
        MAP[row][col] = LIKE[k][0];
        }

        if (row != -1 & col != -1)
        {
            MAP[row][col] = LIKE[k][0];
            continue;
        }

        vector<int> vec = calc_zero(MAP);
        row = vec[0];
        col = vec[1];
        MAP[row][col] = LIKE[k][0];
    }
    print(MAP);
}