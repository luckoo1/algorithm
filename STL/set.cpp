#include <set>
#include <string>
#include <iostream>
using namespace std;
/*
이진tree구조인데 map과 다른점이 있다.
set is an associative container that conains a sorted set of nuique objects of type key
set은 key유형의 고유한 객체 (정렬된)집합을 포함하는 연관 컨테이너를 말한다.
나는 쉽게 tree에 저장한다고 생각하기로 했다. tree로 저장하니깐 당연히 정렬이 되고
map은 hash처럼 key와 value로 저장한다.
*/
/*
multiset과 set의 차이는 set은 요소를 추가할때 중복이 있으면 넣지 않는다
예를들어 1,1,2,3,4를 넣으면 1이 중복되니 set에는 1,2,3,4로 저장된다
반면 multiset은 중복을 허락해서 1,1,2,3,4,5로 저장한다.
*/
/*
map은 자동적으로 작은거부터 저장한다.(자동으로 오름차순)

set<int, greater<string>> ;

*/
int main()
{
    //★set초기화
    set<int> setnum;

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
    // 3 4 5 7

    //★요소 찾기
    set<int>::iterator search = setnum.find(3);

    if (search != setnum.end())
    {
        std::cout << "Found : " << (*search) << '\n';
    }
    else
    {
        std::cout << "Not found\n";
    }
    //Found : 3

    //★요소삭제
    setnum.erase(3);
    cout << "erased set : ";
    for (set<int>::iterator it = setnum.begin(); it != setnum.end(); it++)
    {
        cout << *it << " ";
    }
    //4 5 7

    //★min과 max값 뽑기
    auto iter = --setnum.end();
    cout << (*iter) << endl;//제일 작은수 
    iter = setnum.begin();
    cout << (*iter) << endl;//제일큰수
}