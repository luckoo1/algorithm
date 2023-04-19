#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_rule(int a,int b)
{
    if(a>b)
        return true;
    return false;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    int N,max_score;
    cin>>N>>max_score;
    int cnt_apply,cnt_max,apply_score;
    vector<int> ans_vec;
    for(int i=0;i<N;i++)
    {
        vector<int> apply_score_vec;

        cin>>cnt_apply>>cnt_max;

        for(int j=0;j<cnt_apply;j++)
        {
            cin>>apply_score;
            apply_score_vec.push_back(apply_score);
        }

        sort(apply_score_vec.begin(),apply_score_vec.end(),sort_rule);

        if(cnt_apply<cnt_max)
            ans_vec.push_back(1);
        else
            ans_vec.push_back(apply_score_vec[cnt_max-1]);
    }

    sort(ans_vec.begin(),ans_vec.end());

    int ans = 0;
    int ans_cnt = 0;
    for(int i=0;i<ans_vec.size();i++)
    {
        ans+=ans_vec[i];
        if(ans>max_score)
            break;
        ans_cnt++;
    }
    cout<<ans_cnt;
}