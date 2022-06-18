#include <iostream>
#include <vector>
using namespace std;


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

int main()
{
    vector<vector<int>> MAP(3,ve
    for(int i=0;i<MAP.size();i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            cout<<MAP[i][j]<<" ";
        }
         cout<<endl;
    }
    cout<<endl;

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