//그리디
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int need;
    cin >> need;
    int size_choco = 1;
    while (1)
    {
        if (size_choco >= need)
            break;
        size_choco = size_choco * 2;
    }
    cout<<size_choco<<" ";
    int n=0;
    while (1)
    {
        if(need % size_choco==0)
            break;
        n+=1;
        size_choco = size_choco/2;
    }
    cout<<n;
   
}

#if 0
//나의 허접한 답
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int need;
    cin >> need;
    int size_choco = 1;
    while (1)
    {
        if (size_choco >= need)
            break;
        size_choco = size_choco * 2;
    }
    cout<<size_choco<<" ";
    map<int, int> hash_map;
    int cnt_break = 0;
    while (1)
    {
        hash_map[cnt_break] = size_choco;
        if (size_choco== 1)
            break;
        size_choco = size_choco / 2;
        cnt_break += 1;
    }
    int n = 0;
    while(1){

        if(need % hash_map[n]==0){
            break;
        }
        n++;
    }
    cout<<n;
}
#endif