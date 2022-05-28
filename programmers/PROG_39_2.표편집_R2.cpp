#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string>
using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    string answer(n, 'X');
    set<int> table; // 균형 이진트리 기반
    stack<int> deleted;

    for (int i = 0; i < n; ++i)
    {
        table.insert(i);
    }
    auto iter = table.find(k);

    for (int i = 0; i < cmd.size(); ++i)
    {
        char command = cmd[i][0];

        if (command == 'D')
        { // 아래로
            int down = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            while (down > 0)
            {
                iter = next(iter);
                down--;
            }
        }
        else if (command == 'U')
        { // 위로
            int up = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            while (up > 0)
            {
                iter = prev(iter);
                up--;
            }
        }
        else if (command == 'C')
        { // 삭제
            //현재 포인터가 가리키는 데이터 삭제, 삭제된 데이터 스택에 push
            deleted.push(*iter);
            iter = table.erase(iter);

            // erase -> 삭제된 데이터 이후의 포인터를 가리킴
            // 제일 끝 데이터를 삭제 했다면 마지막 데이터를 가리키도록
            if (iter == table.end())
                iter = prev(iter);
        }
        else
        { // 복구
            table.insert(deleted.top());
            deleted.pop();
        }
    }

    for (int i : table)
        answer[i] = 'O'; // 현재 set 에 남아있는 자료만 체크

    return answer;
}
int main()
{
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;
}
