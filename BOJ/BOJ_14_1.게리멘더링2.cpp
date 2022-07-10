#include <iostream>
#include <vector>
using namespace std;

int N;

void print(vector<vector<int>> a)
{
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

void divied(int r, int c, int d1, int d2)
{
    r = 2-1;
    c = 5-1;
    d1 = 3;
    d2 = 2;
    vector<vector<int>> temp_map(N, vector<int>(N, 0));
    // cout<<r<<","<<c<<","<<d1<<","<<d2<<endl;
    for(int i=0;i<=d1;i++)
    {
        temp_map[r+i][c-i]=5;
    }

    for(int i=0;i<=d2;i++)
    {
        temp_map[r+i][c+i]=5;
    }

    for(int i=0;i<=d2;i++)
    {
        temp_map[r+d1+i][c-d1+i]=5;
    }

    for(int i=0;i<=d1;i++)
    {
        temp_map[r+d2+i][c+d2-i]=5;
    }

    print(temp_map);
}

int main()
{
    cin >> N;
    divied(0,0,0,0);

    #if 0
    vector<vector<int>> MAP(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int d1 = 0; d1 < N; d1++)
            {
                for (int d2 = 0; d2 < N; d2++)
                {
                    if ((x + d1 + d2) < N)
                    {
                        if ((y - d1) >= 0 && (y + d2) < N)
                        {
                            divied(x, y, d1, d2);
                        }
                    }
                }
            }
        }
    }
    #endif
}