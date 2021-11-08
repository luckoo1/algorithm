#include <set>
#include <string>
#include <iostream>
using namespace std;

//이진tree구조인데 map과 다른점이 있다.
//set is an associative container that conains a sorted set of nuique objects of type key
//set은 key유형의 고유한 객체 (정렬된)집합을 포함하는 연관 컨테이너를 말한다.
int main()
{
    //set초기화
    set<int> setnum;

    //set에 요소 추가
    setnum.insert(7);
    setnum.insert(4);
    setnum.insert(3);
    setnum.insert(5);
    setnum.insert(7);

    //set size확인
    cout << "Set size : " << setnum.size() << endl; //중복이 없어서 4가 나온다.
    //4

    //set 출력해보기
    cout << "Set : ";
    for (set<int>::iterator it = setnum.begin(); it != setnum.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    //3 4 5 7

    //set 요소 찾기
    //find의 Return value
    //Iterator to an element with key equivalent to key.
    //If no such element is found, past - the - end(see end()) iterator is returned.set<int>::iterator search = setnum.find(3);
    //STL공부할때 못찾으면 last값을 뱉는다고 배웠었다.
    //https://beobsung.tistory.com/20
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

#if 0
    //아래코드 모르겠다 ㅠㅠ
    //못찾아서 쓰레기 코드 뱉는건가..?
    search = setnum.find(45982309);
    std::cout << "what : " << (*search) << '\n';
#endif

    //요소삭제
    setnum.erase(3);
    cout << "erased set : ";
    for (set<int>::iterator it = setnum.begin(); it != setnum.end(); it++)
    {
        cout << *it << " ";
    }
    //4 5 7
}