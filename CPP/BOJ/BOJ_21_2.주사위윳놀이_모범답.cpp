#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int dice[10]; // 주사위의 입력값
int horse[4]; // 현재 말의 위치

int arr[34];    // 다음에 갈 위치 저장
int score[34];  // 윷놀이판 엔트리의 점수
int turn[34];   // 파란색 화살표가 있는 전환 지점
bool check[34]; // 윷놀이판 엔트리의 말 존재여부

int ans = INT_MIN;

vector<int> vec(10, 0);

void init()
{
    for (int i = 0; i < 21; i++)
        arr[i] = i + 1;
    arr[21] = 21;

    for (int i = 22; i < 27; i++)
        arr[i] = i + 1;

    arr[27] = 20;
    arr[28] = 29;
    arr[29] = 30;
    arr[30] = 25;
    arr[31] = 32;
    arr[32] = 25;

    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;

    for (int i = 0; i < 21; i++)
        score[i] = 2 * i;

    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[31] = 22;
    score[32] = 24;
}

void dfs(int dep)
{

    int temp_ans = 0;
    vec = {0,0,0,0,0,0,0,1,0,0};
    
    for (int i = 0; i < 10; i++)
    {
        int pick_horse = vec[i];
        int cur = horse[pick_horse];
        int move = dice[i];

        if (turn[cur] > 0)
        {
            cur = turn[cur];
            move--;
        }
        while (move--) // 남은 이동횟수만큼 칸 이동
        {
            cur = arr[cur];
        }

        if (cur != 21 && check[cur])
            continue; // 도착위치가 아닌데, 해당 위치에 말이 있다면 못 놓음

        check[cur] = true;
        check[horse[pick_horse]] = false;
        horse[pick_horse] = cur;
        temp_ans += score[cur];
    }

    if (ans < temp_ans)
    {
        ans = temp_ans;
    }

    return;
}

int main()
{
    init();
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    dfs(0);

    cout << ans << endl;
    return 0;
}