#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check_tree(string skill, string tree)
{
    vector<bool> check(tree.size(), false);

    for (int i = 0; i < skill.size(); i++)
        for (int j = 0; j < tree.size(); j++)
            if (skill[i] == tree[j])
            {
                check[j] = true;
                break;
            }

    string temp_ans = "";

    for (int i = 0; i < tree.size(); i++)
        if (check[i] == true)
            temp_ans += tree[i];

    for (int i = 0; i < temp_ans.size(); i++)
        if (skill[i] != temp_ans[i])
            return false;

    return true;
}

int solution(string skill, vector<string> skill_trees)
{
    int ans = 0;

    for (int i = 0; i < skill_trees.size(); i++)
        if (check_tree(skill, skill_trees[i]) == true)
            ans += 1;

    return ans;
}