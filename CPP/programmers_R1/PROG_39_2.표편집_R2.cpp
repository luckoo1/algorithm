#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    int move;
    set<int> table;
    vector<int> history;
    for (int i = 0; i < n; i++)
    {
        table.insert(i);
    }

    auto iter = table.find(k);  //★Point

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'D')
        {
            move = stoi(cmd[i].substr(2, cmd.size() - 1));
            for (int i = 0; i < move; i++)
            {
                iter++; // iter = next(iter);
            }
        }
        else if (cmd[i][0] == 'U')
        {
            move = stoi(cmd[i].substr(2, cmd.size() - 1));
            for (int i = 0; i < move; i++)
            {
                iter--; // iter = prev(iter);
            }
        }
        else if (cmd[i][0] == 'C')
        {
            history.push_back(*iter);
            iter = table.erase(iter);
            if(iter == table.end())
            {
                iter--;
            }
        }
        else if (cmd[i][0] == 'Z')
        {
            int recover = history[history.size()-1];
            table.insert(recover);
            history.pop_back();
        }
    }
    string answer(n,'X');//★Point

    for(int i:table) {answer[i]='O';}

    return answer;
}

int main()
{
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;
}
int main()
{
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;
}
