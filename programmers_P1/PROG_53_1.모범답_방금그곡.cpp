#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(string listen, string total)
{
    if (listen.size() > total.size())
        return false;

    for (int i = 0; i < total.size() - listen.size() + 1; i++) // for (int i = 0; i < total.size() - listen.size(); i++) 해서 틀림
        if (listen == total.substr(i, listen.size()))
        {
            if (total[i + listen.size()] != '#')
            {
                return true;
            }
        }

    return false;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "";
    int ans_length_song = 0;
    int answer_song_length = 0;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        string info = musicinfos[i];
        int start_hour = stoi(info.substr(0, 2));
        int start_min = stoi(info.substr(3, 2));
        int end_hour = stoi(info.substr(6, 2));
        int end_min = stoi(info.substr(9, 2));
        string song_name = info.substr(12, info.substr(12).find(','));
        string radio_song = info.substr(12 + song_name.size() + 1);

        int radio_song_minute = ((end_hour * 60) + end_min) - ((start_hour * 60) + start_min);

        int cnt = 0;
        int j = 0;
        string total_radio_song = "";
        while (1)
        {
            if (radio_song_minute == cnt)
                break;
            total_radio_song += radio_song[j % radio_song.size()];
            if (radio_song[(j + 1) % radio_song.size()] == '#')
            {
                total_radio_song += radio_song[(j + 1) % radio_song.size()];
                j += 2;
            }
            else
            {
                j += 1;
            }
            cnt += 1;
        }

        if (check(m, total_radio_song) == true)
        {
            if (radio_song_minute > answer_song_length)
            {
                answer_song_length = radio_song_minute;
                answer = song_name;
            }
        }
    }

    if (answer == "")
        return "(None)";

    return answer;
}

int main()
{
    string a = "ABCDEFG";
    vector<string> b = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    string c = "CC#BCC#BCC#BCC#B";
    vector<string> d = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
    string e = "ABC";
    vector<string> f = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    string g = "CC#B#CC#B#CC#B#CC#B#";
    vector<string> h = {"03:00,03:30,FOO,CC#B#", "04:00,04:08,BAR,CC#BCC#BCC#B"};

    string ans1 = solution(a, b);
    cout << "ans : " << ans1 << endl;
    string ans2 = solution(c, d);
    cout << "ans : " << ans2 << endl;
    string ans3 = solution(e, f);
    cout << "ans : " << ans3 << endl;
    // string ans4 = solution(g, h);
    // cout << ans4 << endl;
}

// for (auto n : listen_rythm_separate)
// {
//     cout << n << " ";
// }
// cout << endl;
// for (auto n : total_rythm_separate)
// {
//     cout << n << " ";
// }
// cout << endl;