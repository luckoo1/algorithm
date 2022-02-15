#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record)
{
    //빈칸으로 나누어서 vector에 넣어준다.
    vector<vector<string>> separate_record(record.size());
    string temp = "";
    for (int i = 0; i < record.size(); i++)
    {
        for (int j = 0; j < record[i].size(); j++)
        {
            if (record[i][j] != ' ')
                temp += record[i][j];
            else
            {
                separate_record[i].push_back(temp);
                temp = "";
            }
        }
        separate_record[i].push_back(temp);
        temp = "";
    }

    //user_id와 닉네임을 해쉬맵에 넣어준다.
    map<string, string> user_id;
    for (int i = 0; i < separate_record.size(); i++)
    {
        if (separate_record[i][0] != "Leave")
        {
            user_id[separate_record[i][1]] = separate_record[i][2];
        }
    }

    //각userid에 맞게 닉네임을 바꾼다
    for (int i = 0; i < separate_record.size(); i++)
    {
        separate_record[i][1] = user_id[separate_record[i][1]];
    }

    //기록들을 넣어준다.
    vector<string> answer;
    temp = "";
    for (int i = 0; i < separate_record.size(); i++)
    {
        if (separate_record[i][0] == "Enter")
        {
            temp += separate_record[i][1];
            //temp += "is enter.";
            temp += "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (separate_record[i][0] == "Leave")
        {
            temp += separate_record[i][1];
            //temp += "is out.";
            temp += "님이 나갔습니다.";
            answer.push_back(temp);
        }
        temp = "";
    }
    return answer;
}

int main()
{
    vector<string> a{"Enter uid1234 Muzi",
                     "Enter uid4567 Prodo",
                     "Leave uid1234",
                     "Enter uid1234 Prodo",
                     "Change uid4567 Ryan"};
    //["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
    vector<string> ans = solution(a);
}