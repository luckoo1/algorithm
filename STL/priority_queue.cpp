/*
★우선순위 큐란
일반적인 큐(Queue)는 First in-First Out 구조입니다.
즉, 어떤 부가적인 조건 없이 먼저 들어온 데이터가 먼저 나가는 구조였습니다.
하지만 우선순위 큐(Priority Queue)는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나오는 것 것을 말합니다.
우선순위 큐는 힙(Heap)이라는 자료구조를 가지고 구현할 수있기 때문에 이 둘을 묶어서 같이 쓴 것입니다.

[주의] 왜 우선순위 큐는 배열이나 연결리스트로 구현하지 않을까?
(1) 만일 배열로 구현한다고 가정합니다. 우선순위가 높은 순서대로 배열의 가장 앞부분부터 넣는다면, 
우선순위가 높은 데이터를 반환하는 것은 맨 앞의 인덱스를 바로 이용하면 되므로 어렵지 않습니다.
하지만 우선순위가 중간인 것이 들어가야 하는 삽입 과정에서는 뒤의 데이터까지 인덱스를 모두 한 칸씩 뒤로 밀어야 하는 단점이 있습니다.
최악의 경우 삽입해야 하는 위치를 찾기 위해 모든 인덱스를 탐색해야 합니다. 즉 이 때의 시간 복잡도는 자료가 n개라고 할 때 O(n) 이 됩니다. 
→ 배열로 구현 시 시간 복잡도 : 삭제는 O(1), 삽입은 O(n)

(2) 만일 연결리스트로 구현한다고 가정합니다. 이 또한 우선 순위가 높은 순서대로 연결을 시키면, 
우선순위가 높은 데이터의 반환은 배열과 마찬가지로 쉽습니다.
하지만 연결리스트 또한 삽입의 과정 또한 배열과 마찬가지로 그 위치를 찾아야 합니다. 
최악의 경우 맨 끝에까지 가게 됩니다. 
→ 연결리스트로 구현 시 시간 복잡도 : 삭제는 O(1), 삽입은 O(n)

(3) 우선순위 큐를 힙으로 구현한다고 가정합니다. 
힙의 경우 삭제나 삽입 과정에서 모두 부모와 자식 간의 비교만 계속 이루어집니다. (아래에서 다룰 것입니다)
즉, 이진 트리의 높이가 하나 증가할 때마다 저장 가능한 자료의 갯수는 2배 증가하며, 
비교 연산 횟수는 1회 증가합니다. 즉 삭제나 삽입 모두 최악의 경우에는 O(log2n) 의 시간 복잡도를 가집니다. 
→ 힙으로 구현 시 시간 복잡도 : 삭제는 O(log2n), 삽입은 O(log2n)
 
이처럼 배열이나 연결 리스트가 삭제에서는 시간 복잡도의 우위를 점할지라도, 
삽입의 시간 복잡도가 힙 기반이 월등하기 때문에, 편차가 심한 배열과 연결리스트보다는 힙으로 구현하는 것입니다.

★힙이란
위에서 우선순위 큐에 대해서는 간략히 설명했으니, 이를 구현하기 위한 힙에 대해 알아봅시다.
(1) 힙은 Complete Binary Tree(완전 이진 트리) 이다.
(2) 모든 노드에 저장된 값(우선순위)들은 자식 노드들의 것보다 (우선순위가) 크거나 같다.
※ 직접 연결된 자식-부모 노드 간의 크기만 비교하면 됩니다.
※ 힙으로 우선순위 큐를 구현할 때에는 노드에 저장된 값을 우선순위로 봅니다.
따라서 힙은 루트 노드에 우선순위가 높은 데이터를 위치시키는 자료구조가 됩니다.
그러므로 우선순위 큐를 구현하기에 딱 맞는 자료구조 이기도 합니다. 힙에 저장된 노드를 뺄 때마다 우선순위가 높은 데이터 먼저 빠져나오기 때문입니다.
우선순위 큐를 들어가기 전에 힙 자체에 대해서만 살펴보도록 하겠습니다.

최대 힙(Max Heap)은 완전 이진트리이면서, 루트 노드로 올라갈수록 저장된 값이 커지는 구조입니다.
그리고 우선순위는 값이 큰 순서대로 매깁니다.

최소 힙(Min Heap)은 완전 이진트리이면서, 루트 노드로 올라갈수록 값이 작아지는 구조입니다.
그리고 우선순위는 값이 작은 순서대로 매깁니다.
최대 힙이던 최소 힙이던 루트 노드에는 우선순위가 높은 것이 자리잡게 됩니다.
*/

//Priority queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int sz;

    priority_queue<int> p_qu_l;
    p_qu_l.push(1);
    p_qu_l.push(9);
    p_qu_l.push(5);
    p_qu_l.push(4);
    p_qu_l.push(3);
    p_qu_l.push(8);
    sz = p_qu_l.size();
    for (int i = 0; i < sz; i++)
    {
        cout << p_qu_l.top() << ' ';
        p_qu_l.pop();
    }
    cout << '\n';

    priority_queue<int, vector<int>, greater<int>> p_qu_g;
    p_qu_g.push(1);
    p_qu_g.push(9);
    p_qu_g.push(5);
    p_qu_g.push(4);
    p_qu_g.push(3);
    p_qu_g.push(8);
    sz = p_qu_g.size();
    for (int i = 0; i < sz; i++)
    {
        cout << p_qu_g.top() << ' ';
        p_qu_g.pop();
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
using namespace std;

int main()
{

    /*
    make_heap(b,e)
    구간 [b,e)의 순차열을 힙 구조로 만듦
    */

    vector<int> v = {10, 20, 30, 40, 50, 60};
    // 1. 최대 heap 생성
    make_heap(v.begin(), v.end());
    // v = {60,50,30,40,20,10}

    // 2. 최소 heap 생성
    make_heap(v.begin(), v.end(), greater<int>());
    // v= {10,20,50,30,40,60}

    /*
    push_heap(b,e)
    원소가 추가된 상태에서 사용
    추가된 구간 [b,e) heap을 교환하여 heap을 유지함.
    일반적으로 push_back()과 함께 사용
    */

    //위의 예제 수행 후
    v.push_back(35);
    // 마지막에 단순 원소 추가
    // v = {60,50,30,40,20,10,35}
    push_heap(v.begin(), v.end());
    // v = {60,50,35,40,20,10,30}
    // heap 형태를 재계산

    /*
    pop_heap(b,e)
    root node를 (논리적)제거(제일 마지막으로 이동)
    원리
    root node와 마지막 node를 교환
    heap을 유지하도록 교환 반복
    */
    vector<int> v = {10, 20, 30, 40, 50, 60};
    make_heap(v.begin(), v.end());
    // v = {60,50,30,40,20,10}
    pop_heap(v.begin(), v.end());
    // v= {50,40,30,10,20,60}

    /*
    sort_heap(b,e)
    구간 [b,e)를 heap 정렬
    구간 [b,e)가 heap 구조여야 함
    */
    vector<int> v = {10, 20, 30, 40, 50, 60};
    make_heap(v.begin(), v.end());
    // v = {60,50,30,40,20,10}
    sort_heap(v.begin(), v.end());
    // v= {10,20,30,40,50,60}
}

//////////////////////////////////////////////////////////////////////////
//기준점 만들어 보기

#include <iostream>
#include <queue>
#include <functional> // greater
using namespace std;

struct Student
{
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {} // 생성자 정의

    // 그냥 점수에 상관 없이 학번기준 학번이 작은것이 Top 을 유지 한다
    bool operator<(const Student s) const
    {
        return this->id > s.id;
    }
};

int main()
{
    priority_queue<Student> pq;

    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));

    // 학번을 기준으로 작은 것이 먼저 출력이 된다 그 이유는 구조체 내부의 연산자 오버로딩에 있다
    while (!pq.empty())
    {
        Student ts = pq.top();
        pq.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    return 0;
}

/*
이번에는 조금은 다른 방식이지만 학번이 큰 것이 Top을 유지하도록 해보겠습니다 

밑에 부분은 위에서 살펴본 코드와 거의 유사하지만 less<int> 부분만 바뀌었습니다 

priority_queue<int, vector<int>, less<int>> pq;

기본적인 자료형인 int 형을 원소로 쓰고자 한다면 priority_queue<int> pq 와  같이 선언을 하지만 사실은 위에서와 같이 저런 부분이 숨겨져 있는 것입니다. 
less<int> 부분을 내가 원하는 기준을 설정한다면 우선순위를 조작할 수 있습니다.
구조체 cmp를 less <int> 부분에 넣어 주기만 하면 간단합니다 그리고 우리가 사용하는 원소는 Student 타입이겠죠!? 
그래서 main 함수 내부에 우선순위 큐 선언 부분을 priority_queue<Student, vector<Student>, cmp> pq;  로 선언을 한 것입니다
*/

#include <iostream>
#include <queue>
#include <functional> // greater
using namespace std;

struct Student
{
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {} // 생성자 정의
};

// 학번을 기준으로 학번(id) 값이 큰 것이 Top 을 유지 하도록 한다.
struct cmp
{
    bool operator()(Student a, Student b)
    {
        return a.id < b.id;
    }
};

int main()
{
    // 위에서 만든 cmp 구조체를 넣어 준다.

    /*
    template<
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
    > class priority_queue;
    */

    priority_queue<Student, vector<Student>, cmp> pq;

    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));

    while (!pq.empty())
    {
        Student ts = pq.top();
        pq.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    return 0;
}