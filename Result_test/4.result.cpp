#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    vector<int> memorizaiton(n, 1);
    int idx = 2;
    while (memorizaiton[idx] < n)
    {
        memorizaiton[idx] = memorizaiton[idx - 1] * idx;
        idx++;
    }

    int result = 0;
    for (int wide = n; wide >= (n/2) -1 ; wide--)
    {   
    }

    return result;
}
int main()
{
    int ans = solution(10);
    cout << ans;
}

/*
int maxNfactorial = n -1;
int result = 0;

for (int i = 0 ; i<= maxNfactorial; i++)
{
    if (result <  (wide - memorizaiton[i]) * (i+1){
    result = wide - memorizaiton[n]) * (i+1)
}

*/