/*
실패했다.(경우의수 나누어서 생각한것도 틀림)
경우를 나누어서 생각해봤다.

1 : 다탈수있음
1_1 : 남은자리X, 더이상 버스 X -> 마지막사람도착 -1 분
1_2 : 남은자리O, 더이상 버스 X -> 마지막사람도착시간
1_3 : 남은자리X, 더이상 버스 O -> 마지막 버스 도착시간
1_4 : 남은자리O, 더이상 버스 O -> 마지막 버스 도착시간

2 : 다탈수없음
2_1 : 오늘 탈수없다.
마지막버스 도착시간
2_2 : 오늘 탈수있다.
버스못타고 남은사람중에 제일 처음에 있는사람시간을 구한다.
-남은사람중에 제일 처음에 있는사람시간 -1
-남은사람중에 제일 처음에 있는사람시간
위 두경우가 있는데 문제는 "남은사람중에 제일 처음에 있는사람시간 -1"했을때 마지막버스에 이미 Full이면 나도 못타게된다
그럼 "남은사람중에 제일 처음에 있는사람시간"해야하는데.. 만약 이 시간에 999명 도착했으면? 머리아파진다.
이 로직으로는 힘들거같다...
*/
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

    int bus_arrive_time = 9 * 60;
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
                if (bus_arrive_time >= crew[0])
                {
                    last_crew_on_bus = crew[0];
                    crew.erase(crew.begin());
                    on_bus_cnt++;
                }
            }
        }
        if (crew.empty())
        {
            break;
        }
        bus_arrive_time += t;
    }

    int last_crew_arrive_time = change_int_min(timetable[timetable.size() - 1]); //마지막에 도착하는 사람의 시간
    int last_bus_time = (9 * 60) + ((n - 1) * t);                                //마지막 버스 시간

    if (crew.empty()) //다탄경우
    {
        if (how_many_bus == 0) //마지막 버스
        {
            if (on_bus_cnt == m)
            {
                return change_str_min(last_crew_arrive_time - 1); //더이상 자리X, 버스 X
            }
            else
            {
                return change_str_min(bus_arrive_time); //자리O, 버스 X
            }
        }
        return change_str_min(last_bus_time); //버스가 더있는 경우
    }

    if (!crew.empty()) //다 못탄경우
    {
        //오늘 탈수 있는 경우
        vector<int> bus_arrive;
        for (int i = 0; i < n; i++)
        {
            bus_arrive.push_back((9 * 60) + (i * t));
        }
        reverse(bus_arrive.begin(), bus_arrive.end()); //뒷버스부터 나열

        int last_crew = crew[0];
        for (int i = 0; i < bus_arrive.size(); i++)
        {
            if (last_crew >= bus_arrive[i])
            {
                return change_str_min(bus_arrive[i]);
            }
        }
    }
    
    return change_str_min(last_bus_time); //오늘 무조건 못타는 경우
}

int main()
{
    // cout << solution(1, 1, 5, {"08:00", "08:01", "08:02", "08:03"}) << endl;
    // cout << solution(2, 10, 2, {"09:10", "09:09", "08:00"}) << endl;
    // cout << solution(2, 1, 2, {"09:00", "09:00", "09:00", "09:00"}) << endl;
    // cout << solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01"}) << endl;
    cout << solution(1, 1, 1, {"23:59"}) << endl;
    cout << solution(10, 60, 45, {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}) << endl;
    cout << solution(1, 1, 5, {"00:01", "00:01", "00:01", "00:01", "00:01", "00:02", "00:03", "00:04"}) << endl; // 00:00 이걸 해결해야한다!!!
}