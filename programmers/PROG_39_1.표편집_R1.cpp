#include <string>
#include <vector>
#include <iostream>
#define PRINT 0
using namespace std;

int move_table(char where_move, int now, int move, vector<bool> &table)
{
    int cnt = 0;
    if (where_move == 'D')
    {
        while (1)
        {
            now++;
            if (table[now] == false)
            {
                continue;
            }
            cnt++;
            if (cnt == move)
            {
                break;
            }
        }
        return now;
    }
    else
    {
        while (1)
        {
            now--;
            if (table[now] == false)
            {
                continue;
            }
            cnt++;
            if (cnt == move)
            {
                break;
            }
        }
        return now;
    }
}
string solution(int n, int k, vector<string> cmd)
{
    int move;
    int now = k;
    vector<bool> table(n, true);
    vector<int> cmd_vec;
    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'D')
        {
            move = stoi(cmd[i].substr(2, cmd.size() - 1));
            now = move_table('D', now, move, table);
        }
        else if (cmd[i][0] == 'U')
        {
            move = stoi(cmd[i].substr(2, cmd.size() - 1));
            now = move_table('U', now, move, table);
        }
        else if (cmd[i][0] == 'C')
        {
            cmd_vec.push_back(now);
            table[now] = false;
            int flag = 0;
            int temp_now = now;
            if (temp_now == n - 1)
            {
                flag = 1;
            }
            if (flag == 0)
            {
                temp_now++;
                while (1)
                {
                    if (table[temp_now] == true)
                    {
                        break;
                    }
                    if (temp_now == n - 1)
                    {
                        flag = 1;
                        break;
                    }
                    temp_now++;
                }
            }
            if (flag == 1)
            {
                temp_now = now;
                temp_now--;
                while (1)
                {
                    if (table[temp_now] == true)
                    {
                        break;
                    }
                    if (temp_now == 0)
                    {
                        break;
                    }
                    temp_now--;
                }
            }
            now = temp_now;
        }
        
        else if (cmd[i][0] == 'Z')
        {
            int recover = cmd_vec[cmd_vec.size() - 1];
            cmd_vec.pop_back();
            table[recover] = true;
        }
    }

    string answer = "";
    for(int i=0;i<table.size();i++)
    {
        if(table[i]==true)
        {
            answer.push_back('O');
        }
        else
        {
            answer.push_back('X');
        }
    }
    return answer;
}

int main()
{
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;
}