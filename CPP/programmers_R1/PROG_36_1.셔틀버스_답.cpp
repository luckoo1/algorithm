/*
답보고 다시 생각했다.

1 : 다탈수있음
1_1 : 남은자리X, 더이상 버스 X -> 마지막에 버스 타는 사람 도착시간 -1분
1_2 : 남은자리O, 더이상 버스 X -> 마지막사람도착시간이 아니라 ->★마지막 버스 도착시간과 같다
1_3 : 남은자리X, 더이상 버스 O -> 마지막 버스 도착시간
1_4 : 남은자리O, 더이상 버스 O -> 마지막 버스 도착시간

2 : 다탈수없음
2_1 : 오늘 탈수없다. -> 대기하는 사람중 처음에 와도 못탐 ->마지막버스 도착시간
2_2 : 오늘 탈수있다. -> 마지막에 버스 타는 사람 도착시간 -1분
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int change_str_to_int_min(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return (h * 60) + m;
}

string change_int_to_str_min(int t)
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
    sort(timetable.begin(), timetable.end());
    vector<int> crew;
    for (int i = 0; i < timetable.size(); i++)
    {
        crew.push_back(change_str_to_int_min(timetable[i]));
    }

    int bus_arrive_time = 9 * 60;
    int crew_idx = 0;

    for (int i = 1; i <= n; i++, bus_arrive_time += t)
    {
        int in_bus_cnt = 0;
        for (int j = crew_idx; j < timetable.size(); j++)
        {
            if (crew[j] <= bus_arrive_time)
            {
                in_bus_cnt++;
                crew_idx++;
                if (in_bus_cnt == m)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (i == n)
        {
            if (in_bus_cnt == m)
            {
                return change_int_to_str_min(crew[crew_idx-1]-1);
            }
            else
            {
                return change_int_to_str_min(bus_arrive_time);
            }
        }
    }
}

int main()
{
    // cout << solution(1, 1, 5, {"08:00", "08:01", "08:02", "08:03"}) << endl;
    cout << solution(2, 10, 2, {"09:10", "09:09", "08:00"}) << endl;
    cout << solution(2, 1, 2, {"09:00", "09:00", "09:00", "09:00"}) << endl;
    cout << solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01"}) << endl;
    cout << solution(1, 1, 1, {"23:59"}) << endl;
    //cout << solution(10, 60, 45, {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}) << endl;
    //cout << solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01", "00:02", "00:03", "00:04"}) << endl; // 00:00 이걸 해결해야한다!!!
}