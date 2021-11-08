#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

bool check[8] = {false};
vector<int> number;
vector<char> one_char;
string word = "";

void dfs(int dep, int size)
{
    if (dep == size)
    {
        number.push_back(stoi(word));
        return;
    }

    for (int i = 0; i < one_char.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            word.push_back(one_char[i]);
            dfs(dep + 1, size);
            check[i] = false;
            word.pop_back();
        }
    }
}

int solution(string numbers)
{
    for (int i = 0; i < numbers.size(); i++)
        one_char.push_back(numbers[i]);

    for (int i = 1; i <= one_char.size(); i++)
    {
        dfs(0, i);
    }

    for (int i = 0; i < number.size(); i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;

    // unique(number.begin(), number.end());

    // for (int i = 0; i < number.size(); i++)
    // {
    //     cout << number[i] << " ";
    // }
    // cout << endl;

    number.erase(unique(number.begin(), number.end()), number.end());

    for (int i = 0; i < number.size(); i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

int main()
{
    string a = "123";
    string b = "011";

    int ans = solution(b);
    cout << ans;
}