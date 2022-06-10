#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int N, M, K;
int row, col, age;
vector<vector<int>> ENERGY(12, vector<int>(12, 5));
vector<vector<int>> PLUS_ENERGY(12, vector<int>(12, 0));
deque<int> trees[11][11];

int DR[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int DC[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int main()
{
    deque<int> a = {33,4,5,6};
    trees[0][0]=a;
    for(int i=0;i<trees[0][0].size();i++)
    {
        cout<< trees[0][0][i]<<endl;
    }
    
}