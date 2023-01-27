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
/*
1번답
bool sort_rule(DATA a, DATA b)
{
    if (a.cnt != b.cnt)
    {
        return a.cnt<b.cnt;
    }

    return a.data<b.data;
}
*/
/*
2번답
bool sort_rule(DATA a, DATA b)
{
    if (a.cnt != b.cnt)
    {
        if(a.cnt<b.cnt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(a.data<b.data)
         {
            return true;
        }
        else
        {
            return false;
        }
    }

}
*/

/*
틀렸던 답
자동으로 Data정렬해주는 줄 알았다...
bool sort_rule(DATA a, DATA b)
{
    if (a.cnt != b.cnt)
    {
        return true;
    }

    return false;
}
*/

bool sort_rule(DATA a, DATA b)
{
    if (a.cnt != b.cnt)
    {
        return a.cnt<b.cnt;
    }

    return a.data<b.data;
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

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].size() > 100)
        {
            int cut_cnt = a[i].size() - 100;
            for (int k = 0; k < cut_cnt; k++)
            {
                a[i].pop_back();
            }
        }
    }

    return a;
}

vector<vector<int>> rotate(vector<vector<int>> a)
{
    vector<vector<int>> vec;
    //[ㅡ][ㅣ]
    int row_size = a.size();    //세로수 ㅡ의수
    int col_size = a[0].size(); //가로수 ㅣ의수

    vector<int> temp;
    for (int i = 0; i < col_size; i++)
    {
        for (int j = 0; j < row_size; j++)
        {
            temp.push_back(a[j][i]);
        }
        vec.push_back(temp);
        temp.clear();
    }
    return vec;
}

vector<vector<int>> calc(int check)
{
    vector<vector<int>> TEMP_MAP;
    int row_size = MAP.size();
    int col_size = MAP[0].size();
    for (int i = 0; i < row_size; i++)
    {
        vec.clear();
        hash_map.clear();
        for (int j = 0; j < col_size; j++)
        {
            if (MAP[i][j] == 0)
            {
                continue;
            }
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

vector<vector<int>> calc_col()
{
    int row_size = MAP.size();
    int col_size = MAP[0].size();

    vector<vector<int>> TEMP_MAP;

    for (int i = 0; i < col_size; i++)
    {
        vec.clear();
        hash_map.clear();
        for (int j = 0; j < row_size; j++)
        {
            if (MAP[j][i] == 0)
            {
                continue;
            }
            hash_map[MAP[j][i]]++;
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

int R, C, K;
int main()
{
    cin >> R >> C >> K;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> MAP[i][j];
        }
    }

    int answer = 0;
    bool flag = 0;
    for (int i = 0; i <= 100; i++)  /*for (int i = 0; i < 100; i++)*/
    {
        if (MAP.size() >= R && MAP[0].size() >= C)
        {
            if (MAP[R - 1][C - 1] == K)
            {
                flag = 1;
                break;
            }
        }

        answer += 1;

        int row_size = MAP.size();
        int col_size = MAP[0].size();
        if (row_size >= col_size)
        {
            MAP = padding(calc_row());
        }
        else
        {
            MAP = padding(calc_col());
            MAP = rotate(MAP);
        }
    }

    if (flag == 1)
    {
        cout << answer;
    }
    else
    {
        cout << -1;
    }
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