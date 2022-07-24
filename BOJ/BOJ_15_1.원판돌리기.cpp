#include <iostream>
#include <vector>
using namespace std;

int N,M,T;
void PRINT_VEC(vector<vector<int>> vec)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {   
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<int> clock_rotate(vector<int> vec, int k)
{
    for (int i = 0; i < N; i++)
    {
        int temp = vec[i];
        for (int i = N - 1; i >= 1; i--)
        {
            vec[i] = vec[i - 1];
        }
        vec[N- 1] = temp;
    }
    return vec;
}
vector<int> ban_rotate(vector<int> vec, int k)
{
    for (int i = 0; i < N; i++)
    {
        int temp = vec[0];
        for (int i = 0; i < N - 1; i++)
        {
            vec[i] = vec[i + 1];
        }
        vec[0] = temp;
    }
    return vec;
}

int get_average(vector<vector<int>> vec)
{
    int sum = 0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {   
            sum += vec[i][j];
        }
    }
    return sum/(N*M);
}

int main()
{
    cin>>N>>M>>T;

    vector<vector<int>> MAP(N,vector<int>(M,0));
    vector<vector<int>> command(T,vector<int>(3,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {   
            cin>>MAP[i][j];
        }
    }

    for(int i=0;i<T;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>command[T][j];
        }
    }
}