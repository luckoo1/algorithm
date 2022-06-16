#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct DATA
{
    int data;
    int cnt;
    DATA(int data, int cnt)
    {
        this->data = data;
        this->cnt = cnt;
    }
};

vector<vector<int>> MAP(3, vector<int>(3, 0));
vector<DATA> vec;
map<int, int> hash_map;

bool sort_rule(DATA a, DATA b)
{
    if (a.cnt < b.cnt)
    {
        return true;
    }

    return false;
}

vector<vector<int>> padding(vector<vector<int>> a)
{
    int max_size = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int temp_size = a[i].size();
        if (max_size < temp_size)
        {
            max_size = temp_size;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].size() != max_size)
        {
            int padding_cnt = max_size - a[i].size();
            for (int k = 0; k < padding_cnt; k++)
            {
                a[i].push_back(0);
            }
        }
    }
    return a;
}

vector<vector<int>> calc()
{
    vector<vector<int>> TEMP_MAP;
    for (int i = 0; i < MAP.size(); i++)
    {
        vec.clear();
        hash_map.clear();
        for (int j = 0; j < MAP[i].size(); j++)
        {
            hash_map[MAP[i][j]]++;
        }

        for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
        {
            vec.push_back(DATA(iter->first, iter->second));
        }
        sort(vec.begin(), vec.end(), sort_rule);

        vector<int> temp_vec;

        for (int k = 0; k < vec.size(); k++)
        {
            temp_vec.push_back(vec[k].data);
            temp_vec.push_back(vec[k].cnt);
        }
        TEMP_MAP.push_back(temp_vec);
    }
    return TEMP_MAP;
}

void rotate_map()
{

}

int R, C, K;
int main()
{
    int answer = 0;
    cin >> R >> C >> K;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> MAP[i][j];
        }
    }
    //==============================================================================================================
    int row_size = MAP.size();
    int col_size = MAP[0].size();

    if (row_size >= col_size)
    {
        MAP = padding(calc());
    }
    else
    {
        rotate_map();
        MAP = padding(calc());
        rotate_map();
    }

#if 0
    for(int i=0;i<MAP.size();i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            cout<<MAP[i][j]<<" ";
        }
         cout<<endl;
    }
    cout<<endl;
#endif
}