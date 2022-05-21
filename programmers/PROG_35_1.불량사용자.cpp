#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> user_id, vector<string> banned_id)
{
    
    return 99999;
}

int main()
{
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"}) << endl;
}