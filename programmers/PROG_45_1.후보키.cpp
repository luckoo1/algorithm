/*
처음에는 하나만 제거했을때 중복이 있으면 안되는줄 알고 코드를 짜다가 낭패를 봄
예를 들어 [0,1] [0,1,2] 이것만 본거다
사실 [0],[0,1],[0,1,2],[0,1,2,3] 모두 0이 들어가니깐 0만 있으면 후보키가 가능하다.

그리고 또 코드를 짰다..
그런데 또 에러
{{"100", "100", "ryan"},
{"200", "200", "apeach"},
{"300", "300", "tube"},
{"400", "400", "con"},
{"500", "500", "muzi"},
{"600", "600", "apeach"}};
이거와 같이 0번 칼럼과 1번 칼럼이 같다
내코드는 이걸 못찾았다.

그래서 생각해보니..
hash를 clear하지 않았기 때문에 발생!!
*/

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> hash_map;

vector<vector<int>> ans;
vector<vector<int>> temp_ans;
vector<int> temp_ans_row;
bool check[9];

void dfs(int dep, int k, int max_size, int col_size)
{
    if (dep == max_size)
    {
        temp_ans.push_back(temp_ans_row);
        return;
    }

    for (int i = k; i < col_size; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            temp_ans_row.push_back(i);
            dfs(dep + 1, i + 1, max_size, col_size);
            check[i] = false;
            temp_ans_row.pop_back();
        }
    }
}

bool check_key(vector<int> temp, vector<vector<string>> relation)
{
    string temp_key = "";
    for (int i = 0; i < relation.size(); i++)
    {
        for (int j = 0; j < temp.size(); j++)
        {
            temp_key += relation[i][temp[j]];
        }
        hash_map[temp_key] += 1;
        if (hash_map[temp_key] != 1)
            return false;
        temp_key = "";
    }
    return true;
}

bool check_minimality(vector<int> a, vector<int> b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                cnt += 1;
        }
    }

    if (cnt == a.size())
        return false; // no minimality
    else
        return true; // OK minimality
}

int solution(vector<vector<string>> relation)
{
    int cnt_col = relation[0].size();

    for (int k = 1; k <= relation.size(); k++)
        dfs(0, 0, k, cnt_col);

    for (int i = 0; i < temp_ans.size(); i++)
    {
        hash_map.clear();
        if (check_key(temp_ans[i], relation) == true)
            ans.push_back(temp_ans[i]);
    }

    set<int> size_set;
    for (int i = 0; i < ans.size(); i++)
        size_set.insert(ans[i].size());

    vector<int> sz_vec;
    for (auto n : size_set)
        sz_vec.push_back(n);

    for (int i = 0; i < sz_vec.size() - 1; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            if (sz_vec[i] == ans[j].size())
            {
                for (int k = j + 1; k < ans.size(); k++)
                {
                    if (ans[k].size() == sz_vec[i])
                        continue;
                    if (check_minimality(ans[j], ans[k]) == false)
                    {
                        ans.erase(ans.begin() + k);
                        k = k - 1;
                    }
                }
            }
        }
    }

    return ans.size();
}

int main()
{
    vector<vector<string>> a = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}};

    int ans = solution(a);
    cout << "ANS : " << ans << endl;
}