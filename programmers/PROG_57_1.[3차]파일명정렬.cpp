#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string make_capital(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (s[i] == '.')
            break;

        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 97 + 65;
    }
    return s;
}

string get_file_order(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
    }
}

bool sort_rule(string a, string b)
{
}

vector<string> solution(vector<string> files)
{
    sort(files.begin(), files.end(), sort_rule);
    return files;
}

int main()
{
    cout << make_capital("abczz");
    // vector<string> a{"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    // vector<string> ans1 = solution(a);
    // for (auto n : ans1)
    //     cout << n << " ";
    // cout << endl;

    // vector<string> b{"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    // vector<string> ans2 = solution(b);
    // for (auto n : ans2)
    //     cout << n << " ";
    // cout << endl;
}