#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> lines)
{
    map<int, int> hash;
    for (int k = 0; k < lines.size(); k++)
    {
        string s = lines[k];
        int h = stoi(s.substr(11, 2));
        int m = stoi(s.substr(14, 2));
        int sec = stoi(s.substr(17, 2));
        int ms = stoi(s.substr(20, 3));
        int sum_time = (h * 3600 * 1000) + (m * 60 * 1000) + (sec * 1000) + ms;
        string str_long_time = s.substr(24);
        str_long_time.pop_back();
        int long_time = stof(str_long_time) * 1000;
        int begin_time = sum_time - long_time + 1;

        for (int i = begin_time; i < sum_time+1000; i++)
        {
            hash[i]++;
        }
    }

    int answer = 0;
    for (auto iter = hash.begin(); iter != hash.end(); iter++)
    {
        if (iter->second > answer)
        {
            answer = iter->second;
        }
    }

    return answer;
}

int main()
{
    cout << solution({"2016-09-15 01:00:04.002 2.0s",
                      "2016-09-15 01:00:07.000 2s"})
         << endl;
    cout << solution({"2016-09-15 01:00:04.002 2.0s",
                      "2016-09-15 01:00:07.000 2s"})
         << endl;
    // cout << solution({"2016-09-15 20:59:57.421 0.351s",
    //                   "2016-09-15 20:59:58.233 1.181s",
    //                   "2016-09-15 20:59:58.299 0.8s",
    //                   "2016-09-15 20:59:58.688 1.041s",
    //                   "2016-09-15 20:59:59.591 1.412s",
    //                   "2016-09-15 21:00:00.464 1.466s",
    //                   "2016-09-15 21:00:00.741 1.581s",
    //                   "2016-09-15 21:00:00.748 2.31s",
    //                   "2016-09-15 21:00:00.966 0.381s",
    //                   "2016-09-15 21:00:02.066 2.62s"})
    //      << endl;
}
