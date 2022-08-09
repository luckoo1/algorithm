#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define PRINT 0

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

#if PRINT == 1
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
#endif

void reset_rainbow_check(vector<vector<int>> MAP, vector<vector<bool>> &total_visited)
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
}

void reset_check(vector<vector<bool>> &bool_vec)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            bool_vec[i][j] = false;
        }
    }
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


void bfs(vector<vector<int>> &MAP)
{
    queue<DATA> q;
    vector<vector<bool>> total_visited(N + 1, vector<bool>(N + 1, false));
    vector<vector<bool>> now_turn_check(N + 1, vector<bool>(N + 1, false));
    vector<vector<bool>> final_check(N + 1, vector<bool>(N + 1, false));
    int block_cnt = 0;
    int rainbow_cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            /*1. 한 블락씩 확인하자*/
            if (total_visited[i][j] == true)
                continue;
            if (MAP[i][j] == 0 || MAP[i][j] == -1 || MAP[i][j] == 7)
                continue;

            q.push(DATA(i, j));
            total_visited[i][j] = true;
            now_turn_check[i][j] = true;

            int temp_block_cnt = 1;
            int temp_rainbow_cnt = 0;

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
                            /*total_visited는 BFS함수 호출하는 한턴에서 check*/
                            total_visited[move_r][move_c] = true;
                            /*now_turn_check는 하나의 spread가 있을때 check*/
                            now_turn_check[move_r][move_c] = true;
                            temp_block_cnt++;
                            if(MAP[move_r][move_c] == 0)
                                temp_rainbow_cnt++;
                        }
                    }
                }
            }
            int normal_block_cnt = temp_block_cnt - temp_rainbow_cnt;
            /*
            flag가 1이면 계속 진행한다
            모든 탐색이 끝났을때 flag가 0이면 답이 도출된것
            */
            if(temp_block_cnt > 1)
            {
                flag = 1; 
            }
            /*
            final check는 없어질 block을 ture처리하는것
            가장 큰 block을 찾기 위한 조건문
            */
            if(temp_block_cnt > block_cnt)
            {
                block_cnt = temp_block_cnt;
                rainbow_cnt = temp_rainbow_cnt;
                final_check = now_turn_check;
            }
            /*block의 크기가 같으면 무지개block의 수로 판단*/
            if(temp_block_cnt == block_cnt)
            {
                if(temp_rainbow_cnt >= rainbow_cnt)
                {
                    block_cnt = temp_block_cnt;
                    rainbow_cnt = temp_rainbow_cnt;
                    final_check = now_turn_check;
                }
            }

            /*now_turn_check은 전부다 false처리*/
            reset_check(now_turn_check);
            /*now_turn_check에서 무지개만 false처리*/
            reset_rainbow_check(MAP,total_visited);
        }
    }
    /*final_check부분을 없애자*/
    delete_block(final_check, MAP);
    #if PRINT == 1
    cout<<"FINAL"<<endl;
    print(final_check);
    cout<<"DELETE"<<endl;
    print_vec(MAP);
    #endif

    gravity(MAP);
    #if PRINT == 1
    cout<<"GRAVITY"<<endl;
    print_vec(MAP);
    #endif
    rotate(MAP);
    #if PRINT == 1
    cout<<"ROTATE"<<endl;
    print_vec(MAP);
    #endif
    gravity(MAP);
    #if PRINT == 1
    cout<<"AFTER MAP"<<endl;
    print_vec(MAP);
    cout<<"FLAG"<<endl;
    cout<<flag<<endl;
    #endif

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
        #if PRINT == 1
        cout<<"BEFORE MAP"<<endl;
        print_vec(MAP);
        #endif
        bfs(MAP);
        if(flag == 0)
            break; 
        flag = 0;
    }

    cout<<answer;
}