#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int &n, vector<int> &stones, int &k)
{
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - n <= 0)
            cnt++;
        else
            cnt = 0;
        if (cnt >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int Start = 1;
    int End = *max_element(stones.begin(), stones.end());
    while (Start <= End)
    {
        int mid = (Start + End) / 2;
        if (binarySearch(mid, stones, k))
        {
            End = mid - 1;//못건너면 사람 줄여서 줄인 사람은 건널 수 있는지 알아본다.
        }
        else
        {
            Start = mid + 1;//건너면 사람 늘려서 더 건널 수 있는지 알아본다.
        } 
    }
    return Start;
}

int main()
{
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) << endl;
}
/*
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
*/

/*
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
    for (int i = k; i < stones.size(); i++)
    {
        temp_vec.erase(temp_vec.begin());
        temp_vec.push_back(stones[i]);
        #if 0
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
*/