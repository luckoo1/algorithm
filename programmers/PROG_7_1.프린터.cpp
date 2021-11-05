#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check_max(vector<int> vec, int num)
{
    int max_num = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (max_num < vec[i])
            max_num = vec[i];
    }
    if (num == max_num)
        return true;
    else
        return false;
}

int solution(vector<int> priorities, int location)
{
    vector<int> idx;
    int print_num = 0;

    for (int i = 0; i < priorities.size(); i++)
        idx.push_back(i);

    while (1)
    {
        if (check_max(priorities, priorities[0]) == true)
        {
            if (idx[0] == location) //답 도출
            {
                print_num += 1;
                return print_num;
            }

            else //제일 크기는 한데 index가 같지 않았다.
            {
                priorities.erase(priorities.begin());
                idx.erase(idx.begin());
                print_num += 1;
            }
        }
        else
        {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());

            idx.push_back(idx[0]);
            idx.erase(idx.begin());
        }
    }
}

int main()
{
    vector<int> a{2, 1, 3, 2};
    int b = 2;
    vector<int> c{1, 1, 9, 1, 1, 1};
    int d = 0;

    int answer = solution(a, b);
    cout << answer;
}