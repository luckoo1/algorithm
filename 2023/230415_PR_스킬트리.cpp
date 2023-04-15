#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int ans = 0;
    vector<string> vec_cut_word;
    for (int i = 0; i < skill_trees.size(); i++)
    {
        string temp_word = "";
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            if(skill.find(skill_trees[i][j])!=string::npos)
            {
                temp_word.push_back(skill_trees[i][j]);
            }
        }
        vec_cut_word.push_back(temp_word);
    }

    int minus_ans = 0;
    for(int i=0;i<vec_cut_word.size();i++)
    {
        for(int j=0;j<vec_cut_word[i].size();j++)
        {
            if(vec_cut_word[i][j] !=skill[j])
            {
                minus_ans+=1;
                break;
            }
        }
    }
    ans = skill_trees.size()-minus_ans;
    return ans;
}