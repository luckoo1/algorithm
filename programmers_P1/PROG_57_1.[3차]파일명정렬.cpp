/*
C++의 alogorithm 헤더의 sort 함수는 불안정정렬(unstable sort)을 구현하고 있습니다.

이 문제에서는 일부로 정렬 기준을 애매하게 줌으로써 같은 순위의 테스트케이스가 나오게 됩니다.
예를 들어 테케가 ["img01", "img1"] 이라면 img01과 img1은 동일한 순위를 가질겁니다.
그렇다면 결과는 마지막 조건에 의해 기존의 순서를 유지한 ["img01", "img1"]이 나와야 합니다.
이때 불안정정렬은 이 순서를 보장하지 않습니다. 정렬 과정에서 ["img1", "img01"]이란 결과가 나올 수 있다는 것입니다.

따라서 안정정렬을 구현하고 있는 stable_sort()를 사용하면 통과하실수 있을겁니다.
*/

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

vector<string> get_file_order_name(string s)
{
    int i = 0;

    string str_head = "";
    while (1)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            str_head += s[i];
            i += 1;
            continue;
        }
        break;
    }

    string str_tail = "";

    while (1)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            str_tail += s[i];
            i += 1;
            continue;
        }
        break;
    }

    int tail_num = stoi(str_tail);
    str_tail = to_string(tail_num);

    return {str_head, str_tail};
}

bool sort_rule(string a, string b)
{
    a = make_capital(a);
    b = make_capital(b);

    vector<string> a_vec = get_file_order_name(a);
    vector<string> b_vec = get_file_order_name(b);

    string a_head = a_vec[0];
    int a_tail = stoi(a_vec[1]);
    string b_head = b_vec[0];
    int b_tail = stoi(b_vec[1]);

    if (a_head != b_head)
        return a_head < b_head;
    else
        return a_tail < b_tail;
}

vector<string> solution(vector<string> files)
{

    stable_sort(files.begin(), files.end(), sort_rule);
    return files;
}

int main()
{
    vector<string> a{"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    vector<string> ans1 = solution(a);
    for (auto n : ans1)
        cout << n << " ";
    cout << endl;

    // vector<string> b{"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    // vector<string> ans2 = solution(b);
    // for (auto n : ans2)
    //     cout << n << " ";
    // cout << endl;
}