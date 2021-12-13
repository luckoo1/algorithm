#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string m, vector<string> musicinfos)
{

    string answer = "";
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

    string ans = solution(a, b);
    cout << ans << endl;
}