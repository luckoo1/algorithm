//map 인자 출력
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> m = {{"mon", 1}, {"tue", 2}};
    //원래 반복자를 사용해야한다.
    map<string, int>::iterator it;

    //범위기반은 포인터다, auto로 쉽게 해결가능하다
    for (it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << it->second << '\n';

    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << ' ' << iter->second << '\n';

    //index기반은 멤버데이터
    for (auto iter : m)
    {
        cout << iter.first << " " << iter.second << endl;
    }
}

//멤버데이터와 포인터의 차이공부하기