/*
*/
#include <iostream>
#include <vector>
using namespace std;
#define PRINT 0

void print(vector<int> a)
{
    for (auto n : a)
    {
        cout << n << " ";
    }
    cout << endl;
}

int N, K;
vector<int> BELT;

void rotate_BELT()
{
    int temp = BELT[(2 * N) - 1];
    BELT.pop_back();
    BELT.insert(BELT.begin(), temp);
}

int main()
{
    cin >> N >> K;
    int num;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> num;
        BELT.push_back(num);
    }
    //============================================================================================
    vector<int> robot(N, 0);
    int answer = 0;
    #if PRINT
    cout << endl;
    print(BELT);
    print(robot);
    cout << endl;
    #endif
    while (1)
    {
        //벨트회전
        rotate_BELT();
        //로봇도 벨트와 함께 이동
        int temp = robot[N - 1];
        for (int i = N - 1; i >= 1; i--) // N-1 -> 1
        {
            if (robot[i - 1] == 1)
                robot[i] = robot[i - 1];
            robot[i - 1] = 0;
        }
        //로봇이 있으면 없애기
        if (robot[N - 1] == 1)
        {
            robot[N - 1] = 0;
        }
        #if PRINT
        cout << answer << " "<<"rotate"<<endl;
        print(BELT);
        print(robot);
        cout << endl;
        #endif

        //로봇한칸 전진
        for (int i = N - 2; i >= 0; i--) //(N-2) -> 0
        {
            if (robot[i] == 0)
            {
                continue;
            }
            if (robot[i + 1] == 1 || BELT[i + 1] == 0)
            {
                continue;
            }
            BELT[i + 1]--;
            robot[i + 1] = 1;
            robot[i] = 0;
        }
        #if PRINT
        cout << answer << " "<<"robot move"<<endl;
        print(BELT);
        print(robot);
        cout << endl;
        #endif
        //로봇이 있으면 없애기
        if (robot[N - 1] == 1)
        {
            robot[N - 1] = 0;
        }

        //로봇 올리기
        if (BELT[0] > 0)
        {
            BELT[0]--;
            robot[0] = 1;
        }
        #if PRINT
        cout << answer << " "<<"FINAL"<<endl;
        print(BELT);
        print(robot);
        cout << endl;
        #endif

        answer++;

        int cnt = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            if (BELT[i] == 0)
            {
                cnt++;
            }
        }
        if (cnt >= K)
        {
            break;
        }
    }

    cout << answer;
}