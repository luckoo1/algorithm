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

bool check_prime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    for (int i = 0; i < numbers.size(); i++)
        one_char.push_back(numbers[i]);

    for (int i = 1; i <= one_char.size(); i++)
    {
        dfs(0, i);
    }

    sort(number.begin(), number.end());
    number.erase(unique(number.begin(), number.end()), number.end());

    int ans = 0;
    for (int i = 0; i < number.size(); i++)
    {
        if (check_prime(number[i]) == true)
            ans++;
    }

    return ans;
}

int main()
{
    string a = "123";
    string b = "011";

    int ans = solution(b);
    cout << ans;
}