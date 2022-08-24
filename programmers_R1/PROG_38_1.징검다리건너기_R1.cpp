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
    int answer = temp_ans;
    for (int i = 1; i < stones.size()-k+1; i++)
    {
        if(stones[i]>k)
        {
            continue;
        }
        temp_vec.clear();
        for (int j = i; j < i + k; j++)
        {
            temp_vec.push_back(stones[j]);
        }
        #if 1
        for(auto n:temp_vec)
        {
            cout<<n<<" ";
        }
        cout<<endl;
        #endif
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