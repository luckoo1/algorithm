#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int ans = 0;

    int size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(),B.end());
    for (int i = 0; i < size; i++)
    {
        ans += A[i] * B[i];
    }

    return ans;
}
