#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k)
{
    vector<int> temp_vec;

    for (int i = 0; i < k; i++)
    {
        temp_vec.push_back(stones[i]);
    }
    int temp_ans = *max_element(temp_vec.begin(), temp_vec.end());
    int answer = *max_element(temp_vec.begin(), temp_vec.end());

    for (int i = k; i < stones.size(); i++)
    {
        temp_vec.erase(temp_vec.begin());
        temp_vec.push_back(stones[i]);
        temp_ans = *max_element(temp_vec.begin(), temp_vec.end());
        if (answer > temp_ans)
        {
            answer = temp_ans;
        }
    }

    return answer;
}

int main()
{
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) << endl;
}