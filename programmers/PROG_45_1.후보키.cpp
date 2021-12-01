#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> hash_map;

vector<vector<int>> temp_ans;
vector<int> temp;
bool check[9];

void dfs(int dep, int k, int max_size, int col_size)
{
    if (dep == max_size)
    {
        temp_ans.push_back(temp);
        return;
    }

    for (int i = k; i < col_size; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            temp.push_back(i);
            dfs(dep + 1, i + 1, max_size, col_size);
            check[i] = false;
            temp.pop_back();
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

int solution(vector<vector<string>> relation)
{
    int cnt_row = relation.size();
    int cnt_col = relation[0].size();
    vector<vector<int>> ans;
    vector<int> ans_row;
    for (int i = 0; i < cnt_col; i++)
    {
        for (int j = 0; j < cnt_row; j++)
        {
            hash_map[relation[j][i]] += 1;
            if (hash_map[relation[j][i]] != 1)
                break;
            if (j == cnt_row - 1)
            {
                ans_row.push_back(i);
                ans.push_back(ans_row);
                ans_row.clear();
            }
        }
    }
    hash_map.clear();

    for (int k = 2; k <= relation.size(); k++)
    {

        dfs(0, 0, k, cnt_col);

        for (int i = 0; i < temp_ans.size(); i++)
        {
            if (check_key(temp_ans[i], relation) == true)
            {
                ans.push_back(temp_ans[i]);
            }
        }
    }

    //minimality체크

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

// 조합 경우의 수
/*
 1(0001) - 학번
 2(0010) - 이름
 3(0011) - 이름, 학번
 4(0100) - 전공
 5(0101) - 학번, 전공
 6(0110) - 이름, 전공
 7(0111) - 학번, 이름, 전공
 8(1000) - 학년
 9(1001) - 학번, 학년
 10(1010) - 이름, 학년
 11(1011) - 학번, 이름, 학년
 12(1100) - 이름, 학번
 13(1101) - 학번, 전공, 학년
 14(1110) - 이름, 전공, 학년
 15(1111) - 학번, 이름, 전공, 학년
 */