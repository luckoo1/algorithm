#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    return answer;
}

int main()
{
    vector<int> a = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (auto n : a)
        cout << n << " ";
    cout << endl;
    vector<int> b = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    for (auto n : b)
        cout << n << " ";
    cout << endl;
    vector<int> c = solution("{{20,111},{111}}");
    for (auto n : c)
        cout << n << " ";
    cout << endl;
    vector<int> d = solution("{{123}}");
    for (auto n : d)
        cout << n << " ";
    cout << endl;
    vector<int> e = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for (auto n : e)
        cout << n << " ";
    cout << endl;
}