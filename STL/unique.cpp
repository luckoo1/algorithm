/*
제대로 중복값을 제거하려면 unique함수 호출 전, 정렬과정이 반드시 필요합니다

인접한 원소들을 차례로 중복검사를 해나가기 때문에, 동 떨어져 있으면 중복되어 있다는 것을 못한다.
그렇기 때문에 unique를 해주기 앞서, sorting을 하여 같은 값의 원소들을 모아주어야 합니다!

s.erase(unique(s.begin(), s.end()), s.end());
*/
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> s;

int main()
{
    s.push_back(1);
    s.push_back(2);
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(1);
    s.push_back(2);

    cout << "vector" << endl;
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    //1 2 1 3 2 1 2
    cout << "unique" << endl;
    unique(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    //1 2 1 3 2 1 2
    /*
    아무 변화가 없다.
    unique는 연속된 중복 원소를 vector의 제일 뒷부분으로 쓰레기값으로 보낸다
    동 떨어져 있으면 중복되어 있다는 것을 못 알아챕니다 
    */
    cout << "sort" << endl;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    //1 1 1 2 2 2 3

    cout << "unique" << endl;
    unique(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
    //1 2 3 2 2 2 3

    cout << "sort->unique" << endl;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    //1 2 3
}

//#######################################################################
//C++ unique reference
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // a vector containing several duplicate elements
    std::vector<int> v{1, 2, 1, 1, 3, 3, 3, 4, 5, 4};
    auto print = [&](int id)
    {
        std::cout << "@" << id << ": ";
        for (int i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    };
    print(1);

    // remove consecutive (adjacent) duplicates
    auto last = std::unique(v.begin(), v.end());
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(2);

    // sort followed by unique, to remove all duplicates
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    print(3);

    last = std::unique(v.begin(), v.end());
    // v now holds {1 2 3 4 5 x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(4);
}
/*
unique는 두 개의 포인터로 작동합니다. 두 포인터의 이름은 first와 result입니다.
first는 무엇일까요? 단어 의미대로 벡터의 맨 첫 번째 원소를 가리키는 포인터입니다.
따라서 비교가 진행될 수록 다음 원소로 한칸 씩 이동합니다.
그럼 result는 무엇일까요? 비교 시 중복 원소가 아니라고 판단한 경우 값을 입력하는 곳을 가리키는 포인터입니다.
그래서 정확히 말하자면 unique는 "result가 가리키고 있는 값과 first가 가리키고 있는 값이 다르다면 
result를 한 칸 옮기고 거기에 first가 가리키는 값을 덮어 씌우는 라이브러리입니다."
그런데 result는 포인터이죠? 포인터는 동시에 하나의 값만을 가리킵니다.
따라서 이전에 1을 가리키고 다음에 2를 가리킨 다음 다시 1을 가리킨다면 이것이 중복 원소인지 알지 못합니다.
그럼으로 정렬 하여 같은 값을 가지는 원소를 이웃하게 배치해야 합니다. 그러면 이전에 나온 원소가 탐색이 진행 되도 다시 나오지 않을테니까 말이죠.
만약 그러지 않으면 중복된 원소의 값이 또 나올 수도 있고 아닐 수도 있습니다. 이를 정확히 알 수 없음으로 뒤에 물음표가 있는 것입니다.
*/
