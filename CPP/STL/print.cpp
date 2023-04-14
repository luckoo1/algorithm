#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T value)
{
    cout << value << endl;
}

template <typename T>
void print(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <typename T>
void print(vector<vector<T>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
    }
    cout << endl;
}

//iterator로 해보자