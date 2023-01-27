#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    vector<int> memorizaiton(n, 1);
    int idx = 2;
    while (memorizaiton[idx] < n)
    {
        memorizaiton[idx] = memorizaiton[idx - 1] + idx;
        idx++;
    }
    
    int result = 0;
    for (int wide = n; wide >= (n / 2) - 1; wide--)
    {
        for (int j = n - wide-1; j >= 1; j--)
        {
            if(wide + memorizaiton[j]==n)
            {
                if(result < wide * j+1)
                {
                    result = wide * (j+1);
                }
            }
        }
    }

    return result;
}
int main()
{
    int ans = solution(11);
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