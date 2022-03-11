#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check[1000001];
string answer = "";

void dfs(int dep, int index, const string &number, int k)
{
    if (dep == k)
    {
        string temp_str = "";
        for (int i = 0; i < number.size(); i++)
        {
            if (check[i] == false)
            {
                temp_str.push_back(number[i]);
            }
        }
        
        if (answer < temp_str)
        {
            answer = temp_str;
        }
        return;
    }

    for (int i = index; i < number.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            dfs(dep + 1, i + 1, number, k);
            check[i] = false;
        }
    }
}

string solution(string number, int k)
{

    dfs(0, 0, number, k);
    return answer;
}

int main()
{
    cout << solution("1924", 2) << endl;
}