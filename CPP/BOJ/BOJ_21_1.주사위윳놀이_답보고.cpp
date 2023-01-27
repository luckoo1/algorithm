/*
1.
안녕하세요 저도 29%에서 틀려서 인터넷이랑 질문게시판 찾아봤는데요
현재의 말이 이동할 다음 자리에 이미 다른 말이 있는 경우를 아예 제외하는거로 수정해보세요
저는 그렇게 바꿔서 통과했습니다.
before : 말이 움직일 때 이미 말이 있으면 이동을 취소하고 다음 명령으로 넘어간다
after : 말이 움직일 때 이미 말이 있으면 해당 테스트케이스 자체를 제외 (return)
추가적으로 제 소스가 맞는지 검증한 반례를 아래 작성했습니다.
5 5 5 5 5 1 1 1 1 1
답은 167
저는 before로 구현했을때 173이 나와가지고 하루 정도 고민을 했는데요
왜 문제가 제시하는 조건이 after인지는 이해가 안가요

★부분 continue에서 return 처리

2.맵을 1차원으로 처리해서 시간초과 극복했나??


*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int dice[10]; // 주사위의 입력값

int arr[34];    // 다음에 갈 위치 저장
int score[34];  // 윷놀이판 엔트리의 점수
int turn[34];   // 파란색 화살표가 있는 전환 지점

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
    if (dep == 10)
    {
        vector<bool> check(34,false);
        vector<int> horse(4,0);
        int temp_ans = 0;
        for (int i = 0; i < 10; i++)
        {
            int pick_horse = vec[i];
            int cur = horse[pick_horse];
            if(cur == 21)
            {
                continue;
            }
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
                return; //★ 도착위치가 아닌데, 해당 위치에 말이 있다면 못 놓음
            
            check[cur] = true;
            check[horse[pick_horse]] = false;
            horse[pick_horse] = cur;
            temp_ans += score[cur];

        }

        if(ans<temp_ans)
        {
            ans = temp_ans;
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vec[dep] = i;
        dfs(dep + 1);
    }
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