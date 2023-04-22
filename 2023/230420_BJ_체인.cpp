//그리디
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    //freopen("Input.txt", "r", stdin);
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int cnt = 0;
    while (1)
    {
        if(vec.size()==1)
            break;
        if (vec[0] > 0)
        {
            cnt++;
            vec[0] = vec[0] - 1;
            vec[vec.size() - 2] = vec[vec.size() - 2] + vec[vec.size() - 1];
            vec.pop_back();
        }
        if(vec[0]==0)
        {
            vec.erase(vec.begin());
        }
    }
    cout<<cnt;
}