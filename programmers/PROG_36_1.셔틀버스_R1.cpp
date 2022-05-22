#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int change_int_min(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return (h * 60) + m;
}

string change_str_min(int t)
{
    string h = to_string(t / 60);
    string m = to_string(t % 60);

    if (m.size() == 1)
    {
        m = "0" + m;
    }
    if (h.size() == 1)
    {
        h = "0" + h;
    }

    return h + ":" + m;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    int how_many_bus = n;
    int total_crew_cnt = timetable.size();
    sort(timetable.begin(), timetable.end());
    vector<int> crew;
    for (int i = 0; i < timetable.size(); i++)
    {
        crew.push_back(change_int_min(timetable[i]));
    }

    int flag = 0;
    int arrive_time = 9 * 60;
    int on_bus_cnt = 0;
    int last_crew_on_bus;
    while (how_many_bus != 0)
    {
        how_many_bus -= 1;
        on_bus_cnt = 0;

        for (int i = 0; i < m; i++)
        {
            if (!crew.empty())
            {
                if (arrive_time >= crew[0])
                {
                    last_crew_on_bus = crew[0];
                    crew.erase(crew.begin());
                    on_bus_cnt++;
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        arrive_time += t;
    }

    int last_crew_arrive_time = change_int_min(timetable[timetable.size() - 1]); //마지막에 도착하는 사람의 시간
    int last_bus_time = (9 * 60) + ((n - 1) * t);                                //마지막 버스 시간


    if (!crew.empty()) //다못탔을경우 "다음날 마지막 버스에 타는 경우"만 있다고 생각했다.
    {

        return change_str_min(last_bus_time);
    }

    if (how_many_bus == 0) //마지막 버스
    {
        if (on_bus_cnt == m)
        {
            return change_str_min(last_crew_arrive_time - 1);
        }
        else
        {
            if (last_crew_on_bus <= 9 * 60)
            {
                return "09:00";
            }
            return change_str_min(last_crew_arrive_time);
        }
    }


    return change_str_min(last_bus_time); //마지막버스시간
}

int main()
{
    cout << solution(1, 1, 5, {"08:00", "08:01", "08:02", "08:03"}) << endl;
    cout << solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01", "00:02", "00:03", "00:04"}) << endl; // 00:00 이걸 해결해야한다!!!
    // cout << solution(2, 10, 2, {"09:10", "09:09", "08:00"}) << endl;
    // cout << solution(2, 1, 2, {"09:00", "09:00", "09:00", "09:00"}) << endl;
    // cout << solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01"}) << endl;
    // cout << solution(1, 1, 1, {"23:59"}) << endl;
    // cout << solution(10, 60, 45, {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}) << endl;
}