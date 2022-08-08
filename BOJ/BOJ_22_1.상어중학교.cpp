#include <iostream>
#include <vector>
#include <queue>
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

int N, M;
int DR[4] = {0, 0, 1, -1};
int DC[4] = {-1, 1, 0, 0};
int answer = 0;
int flag = 0;

void print_vec(vector<vector<int>> a)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(vector<vector<bool>> a)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<bool>> reset_rainbow_check(vector<vector<int>> MAP, vector<vector<bool>> total_visited)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (MAP[i][j] == 0)
            {
                total_visited[i][j] = false;
            }
        }
    }
    return total_visited;
}

vector<vector<bool>> reset_check(vector<vector<bool>> bool_vec)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            bool_vec[i][j] = false;
        }
    }
    return bool_vec;
}

int count_rainbow_in_block(vector<vector<int>> MAP, vector<vector<bool>> now_turn_check)
{
    int cnt;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (MAP[i][j] == 0 && now_turn_check[i][j] == true)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void rotate(vector<vector<int>> &MAP)
{
    vector<vector<int>> return_MAP;
    vector<int> temp;
    for (int c = N; c >=1; c--)
    {
        for (int r = 1; r<=N; r++)
        {
            temp.push_back(MAP[r][c]);
        }
        return_MAP.push_back(temp);

        temp.clear();
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            MAP[i+1][j+1] = return_MAP[i][j];
        }
    }

}

void gravity(vector<vector<int>> &MAP)
{

    for (int c = 1; c <= N; c++)
    {
        for (int r = N - 1; r >= 1; r--)
        {
            if (MAP[r][c] == 7 || MAP[r][c] == -1)
                continue;
            int num = MAP[r][c];
            int move_r = r;
            while (1)
            {
                if(move_r > N-1)
                    break;
                if(MAP[move_r+1][c] == -1)
                    break;
                
                if(MAP[move_r+1][c] == 7)
                {
                    MAP[move_r+1][c] = num;
                    MAP[move_r][c] = 7;
                }
                move_r++;

            }
        }
    }
}

void delete_block(vector<vector<bool>> final_check, vector<vector<int>> &MAP)
{
    int temp_ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (final_check[i][j] == true)
            {
                MAP[i][j] = 7;
                temp_ans++;
            }

        }
    }
    if(temp_ans ==1)
    {
        return;
    }
    answer += temp_ans*temp_ans;
}

int check_finish(vector<vector<bool>> now_turn_check,vector<vector<int>> MAP)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(MAP[i][j] == -1)
                continue;
            if(MAP[i][j] == 0)
                continue;
            if(MAP[i][j] == 7)
                continue;
            if(now_turn_check[i][j]==true)
                cnt++;
        }
    }


    return cnt;
}

void bfs(vector<vector<int>> &MAP)
{
    queue<DATA> q;
    vector<vector<bool>> total_visited(N + 1, vector<bool>(N + 1, 0));
    vector<vector<bool>> now_turn_check(N + 1, vector<bool>(N + 1, 0));
    vector<vector<bool>> final_check(N + 1, vector<bool>(N + 1, 0));
    int cnt = 0;
    int rainbow_cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (total_visited[i][j] == true)
                continue;
            if (MAP[i][j] == 0 || MAP[i][j] == -1 || MAP[i][j] == 7)
                continue;

            q.push(DATA(i, j));
            total_visited[i][j] = true;
            now_turn_check[i][j] = true;
            int temp_cnt = 0;

            int color = MAP[i][j];
            while (!q.empty())
            {
                int now_r = q.front().r;
                int now_c = q.front().c;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int move_r = now_r + DR[k];
                    int move_c = now_c + DC[k];
                    if (move_r < 1 || move_c < 1 || move_r > N || move_c > N)
                        continue;
                    if (MAP[move_r][move_c] == -1)
                        continue;
                    if (MAP[move_r][move_c] == color || MAP[move_r][move_c] == 0)
                    {
                        if (total_visited[move_r][move_c] == false)
                        {
                            q.push(DATA(move_r, move_c));
                            total_visited[move_r][move_c] = true;
                            now_turn_check[move_r][move_c] = true;
                            temp_cnt++;
                        }
                    }
                }
            }


            if (cnt <= temp_cnt)
            {
                if (cnt == temp_cnt)
                {
                    int temp_rainbow_cnt = count_rainbow_in_block(MAP, now_turn_check);
                    if (temp_rainbow_cnt > rainbow_cnt)
                    {
                        rainbow_cnt = temp_rainbow_cnt;
                        cnt = temp_cnt;
                        final_check = now_turn_check;
                    }
                }
                else
                {
                    cnt = temp_cnt;
                    final_check = now_turn_check;
                }
            }


            int temp_flag = check_finish(now_turn_check,MAP);
            if(flag < temp_flag)
            {
                flag = temp_flag;
            }
            now_turn_check = reset_check(now_turn_check);
            total_visited = reset_rainbow_check(MAP, total_visited);
        }
    }
    delete_block(final_check, MAP);
    gravity(MAP);
    rotate(MAP);
    gravity(MAP);

    print_vec(MAP);
    cout<<endl;
    print(final_check);
    cout<<endl;

}
int main()
{
    cin >> N >> M;
    vector<vector<int>> MAP(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    while(1){
        if(flag ==1)
            break;
        flag = 1;
        bfs(MAP);
        cout<<answer<<endl;

    }

    cout<<answer;
}