#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

long long calculation(long long a, long long b, char expr)
{
    if (expr == '*')
    {
        return a * b;
    }
    else if (expr == '+')
    {
        return a + b;
    }
    else if (expr == '-')
    {
        return a - b;
    }
}

bool check_num(char a)
{
    if (a >= '0' && a <= '9')
        return true;

    return false;
}

vector<string> temp_express_ans;

bool check[3];
void dfs(int dep, string temp, vector<long long> &numbers, vector<char> &express)
{
    if (dep == express.size())
    {
        temp_express_ans.push_back(temp);
        return;
    }
    for (int i = 0; i < express.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            temp += express[i];
            dfs(dep + 1, temp, numbers, express);
            check[i] = false;
            temp.pop_back();
        }
    }
}

long long solution(string expression)
{
    vector<long long> numbers;
    set<char> express_set;
    vector<char> order_express;
    vector<char> express;
    string num = "";

    for (int i = 0; i < expression.size(); i++)
    {
        if (check_num(expression[i]))
            num += expression[i];
        else
        {
            numbers.push_back(stoi(num));
            num = "";
            express_set.insert(expression[i]);
            order_express.push_back(expression[i]);
        }
    }
    numbers.push_back(stoi(num));

    for (auto iter = express_set.begin(); iter != express_set.end(); iter++)
        express.push_back(*iter);

    dfs(0, "", numbers, express);

    //vector<int> numbers : 숫자 순서
    //vector<char> order_express : 수식 순서
    //vector<string> temp_express_ans : 수식 우선순위 나열
    long long ans = 0;
    long long temp_ans = 0;
    for (int i = 0; i < temp_express_ans.size(); i++)
    {
        vector<long long> copy_numbers = {numbers.begin(), numbers.end()};
        vector<char> copy_order_express = {order_express.begin(), order_express.end()};
        for (int j = 0; j < temp_express_ans[i].size(); j++)
        {
            for (int k = 0; k < copy_order_express.size(); k++)
            {
                if (temp_express_ans[i][j] == copy_order_express[k])
                {
                    long long calc = calculation(copy_numbers[k], copy_numbers[k + 1], copy_order_express[k]);
                    copy_numbers[k] = calc;
                    copy_numbers.erase(copy_numbers.begin() + k + 1);
                    copy_order_express.erase(copy_order_express.begin() + k);
                    k = k - 1;
                }
            }
        }

        temp_ans = copy_numbers[0];
        if (temp_ans < 0)
        {
            temp_ans = -temp_ans;
        }

        if (temp_ans > ans)
        {
            ans = temp_ans;
        }
    }

    return ans;
}

int main()
{
    string a = "100-200*300-500+20";
    long long ans = solution(a);
    cout << ans;
}