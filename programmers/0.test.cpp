#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    //★set초기화
    set<int,less<int>> setnum;

    //★set에 요소 추가
    setnum.insert(7);
    setnum.insert(4);
    setnum.insert(3);
    setnum.insert(5);
    setnum.insert(7);

    //★set size확인
    cout << "Set size : " << setnum.size() << endl; //중복이 없어서 4가 나온다.
    //4

    //★set 출력해보기
    cout << "Set : ";
    for (set<int>::iterator it = setnum.begin(); it != setnum.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}