#include <iostream>
#include <set> // Red Black Tree로 구현

int main()
{
    std::set<int> s;

    s.insert(20);
    s.insert(30);
    s.insert(15);
    s.insert(5);
    s.insert(40);
    s.insert(25);

    //핵심 1. set은 루트부터 비교로만 넣을 수 있다.(insert통해서)
    //        s.push_front(300); s.push_back(300);안된다.
    //핵심 2. 반복자는 읽기 전용이다.
    //        *p=300; 안된다.
    //        int n = *p;
    //핵심 3. 아래의 코드를 평가해봐라

    auto ret = std::find(s.begin(), s.end(), 30); //에러는 없다.

    //s.begin()부터 s.end()까지 ++로 이동하면서 찾는다 => 선형검색
    //STL 핵심 : 원하는 기능이 있으면
    //A. 멤버함수가 있는지 먼저 찾아라
    //B. 멤버가 없을때 일반함수(알고리즘)에서 찾아라
    auto ret2 = s.find(30);
    //위의 코드는 이진검색이 된다.

    //항상 "STL" 컨테이너 사용시 - 자료구조(메모리 모양)을 잘 생각하면서 사용해라

    auto p = s.begin();
    while (p != s.end())
    {
        std::cout << *p << std::endl;
        ++p;
    }
}

///////////////////////////////////
//https://beobsung.tistory.com/19
/*
5. 검색실패시 반환값 변경
   nulptr을 반환하지 말고 "last"를 반환하자

   장점은 find의 구현이 좀더 간결하고 빨라진다.
   find() 반환값은 결국 다음 검색 구간의 시작이 된다.
   아래 함수가 "C++표준에 이미 있는 std::find라는 함수다
*/
#include <iostream>
template <typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
    while (first != last && *first != c)
    {
        ++first;
    }
    return first // last ? nullptr : first;  //a번주석
}
int main()
{
    double x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    double *p = find(x, x + 3, 5); //1. x+3에 있는 4는 검색대상이 되지 않는다.
                                   //   검색 성공시 x+3은 나올 수 없다.
                                   //   검색 실패시 x+3을 반환하면 어떨까?
    // 실제 검색은 1~4만한다. 다시 4부터 검색을 시작하고 싶지 않나? 4의 위치를 아는 건 중요하지 않나
    // 리턴값을 x+3을해서 다시 거기부터 시작하게 하자.
    // 속도가 빨라진다.
    // 이유는? a번 주석으로 가라
    // a번쪽이 주석처리 되어서 속도가 빨라짐

    if (p == x + 3) //3. x+3으로 이거 바꿈
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << *p << std::endl;
}