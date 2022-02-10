#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> v; // vector

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator iter = v.begin(); // iterator

    cout << iter[3] << endl; // random access

    iter += 2;
    cout << *iter << endl; //

    // loop
    for (iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
//#######################################################################

#include <iostream>
#include <vector>
#include <list>

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8};

    int *px = x;
    ++px;
    *px;
    // 1.요소에 접근할때 이런식으로 접근을 했었다.
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};

    /*
    2.
    리스트는 연속되지 않은데
    그럼에도 불구하고 ++을 연산자 재정의를 해서
    처음꺼 꺼내서 ++로 뒤로 이동할 수 있다.
    */
    std::list<int>::iterator p1 = s.begin();
    //이게 좀 복잡하네..
    // std안에있는 list<int>안에 iterator쓰자는 말
    auto p2 = s.begin();
    // auto라고 편하게 적자

    ++p1;
    ++p2;

    int n1 = *p1;
    int n2 = *p2;

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
}
/*
반복자(iterator)
컨테이너의 요소를 가리키는 포인터와 유사한 객체
++,*연산자등을 재정의해서 포인터와 유사하게 동작하도록 만든 것
list<int>::iterator가 정확한 타입
멤버함수 begin()을 통해서 꺼낼 수 있다.
*/
//#######################################################################

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};

    // std::list<int>::iterator p = s.begin();
    //아래와같이 사용하자
    auto p1 = s.begin();

    auto p2 = s.end(); //마지막 다음 요소
    *p2 = 10;          // runtime error
    //마지막 다음에는 메모리를 할당한적이 없다.

    // end를 아래와 같이 사용할 수 있다
    while (p1 != s.end())
    {
        int n = *p1;
        ++p1;
    }
}

/*
반복자(iterator)주의 사항
end로 꺼내는 반복자는 마지막 요소가 아닌 마지막 다음 요소를 가리킨다.
*/
//#######################################################################

#include <iostream>
#include <vector>
#include <list>

int main()
{
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8};
    /*
    s를 vector도 아닌, list도 아닌 배열로 사용했다고 가정해보자
    그럼 s는 객체가 아니므로 멤버함수가 없다
    아래의 코드는 사용이 불가능하다.
    */
    /*
    auto p1 = s.begin();
    auto p2 = s.end();
    *p2 = 10;

    while (p1 != p2)
    {
        int n = *p1;
        ++p1;
    }
    */

    /*
    아래와 같이 사용하자
    std안에 begin()과 end()일반함수가 있다.
    일반함수 만들때 인자로 STL컨테이너 받는버전만들고
    진짜배열 받는버전도 만들어서 진짜배열받는 버전에는 pointer리턴하면 되잖아
    */
    /*
    auto로 받았으니깐 진짜배열이면 int*로 하면됨
    int*면 ++가능!
    아래코드 컴파일 문제없다
    */
    auto p1 = std::begin(s);
    auto p2 = std::end(s);

    while (p1 != p2)
    {
        int n = *p1;
        ++p1;
    }
}
//#######################################################################

#include <iostream>
#include <vector>
#include <list>
//위의 코드에서 s를 list로 바꾸어도 문제가 없다
int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};

    auto p1 = std::begin(s);
    auto p2 = std::end(s);

    while (p1 != p2)
    {
        int n = *p1;
        ++p1;
    }
}

/*
반복자 꺼내기
멤버함수 begin/end사용
일반함수 begin/end사용-C++11부터
*/
//#######################################################################
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    /*
    1.[]연산을 사용한 컨테이너 접근
    vector,deque은 사용가능
    list는 []연산자 사용이 불가
    */
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    // 2. range for
    for (const auto &n : v) //"auto&"를 썼다.
    {
        std::cout << n << std::endl;
    }

    // 3.반복자 사용
    auto p1 = std::begin(v);
    while (p1 != std::end(v))
    {
        std::cout << *p1 << std::endl;
        ++p1;
    }
}
/*
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
for(int elem : arr)
{
cout << elem << endl;
}

이런식으로 위쪽 기본편에서 배운데로 하게 되면, arr 배열에 있는 인자를 elem 이라는 새로운 변수에 복사를 하게 됩니다.
매 반복문이 돌때마다 아래처럼 복사가 됩니다.

elem = arr[0];
elem = arr[1];
elem = arr[2];

복사를 하게되면 단점이 많습니다.
1. 복사를 했기 때문에 배열의 원래 값를 변경하지 못합니다.
2. 복사를 했기 때문에 복사비용이 발생합니다.
이러한 단점을 보완하기 위해서는 C++의 & (참조자, reference)를 이용하면 됩니다.

▼ C++ range based for문을 reference로 사용하는 방법.
for(int& elem : arr)
{
elem += 1;    //arr[ ] 값도 변경됨.
cout << elem << endl;
}

for(데이터 타입& 변수이름 : 데이터리스트) 와 같이 데이터 타입 뒤에 레퍼런스(&)를 붙이는 방식으로 한다면,
배열의 해당 인자의 값복사가 아닌 변수의 reference(=참조자, 레퍼런스)를 가지고 오게 됩니다.
이렇게 할때의 이점을 아래와 같습니다.
1. 복사비용이 들지 않아서 비용이 감소 합니다.
2. 배열의 원래 원소를 변경할 수 있습니다.

이렇게 되면 다 해결이 되어서 좋지만, 복사비용이 안드는 것은 좋은데 반복문 내부에서 변경이 일어나지 않아야 하는 경우도 존재하죠.
이런 경우에는 const와 reference를 같이 사용하면됩니다.

▼ C++ range based for문을 const와 reference로 사용하는 방법.
for(const int& elem : arr)
{
elem += 1;    // 불가능.
cout << elem << endl;
}
for(const 데이터 타입& 변수이름 : 데이터리스트) 이런방식으로 데이터 타입 앞에 const를 붙이면 값 변경이 불가능하게 됩니다.
그러면 복사비용이 들지 않고 배열의 값을 이용할 수 있고, 배열의 값을 변경하지 않는걸 보장할 수 있게 됩니다.

const & 를 사용할지, &를 사용할지 아니면 그냥 복사로 사용할지는 각 상황에 맞게 잘 판단해서 하면 됩니다.

*/
//#######################################################################

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    auto p1 = std::begin(s);
    auto p2 = std::end(v);

    ++p1;
    ++p2;

    int n1 = *p1;
    int n2 = *p2;
}

/*
반복자의 장점 : 자료구조에 상관없이 동일한 방법으로 접근이 가능
GOF's 디자인패턴 중 "Iterator"패턴
*/