#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sort_rule(pair<int, string> a,pair<int, string> b)
{
    return a.second > b.second;
}

int main(void)
{
    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(99, "a"));
    v.push_back(pair<int, string>(79, "b"));
    v.push_back(pair<int, string>(80, "c"));
    v.push_back(pair<int, string>(88, "d"));
    v.push_back(pair<int, string>(92, "e"));
    v.push_back(pair<int, string>(84, "f"));
    v.push_back(pair<int, string>(97, "g"));
    v.push_back(pair<int, string>(82, "h"));
    v.push_back(pair<int, string>(90, "i"));
    sort(v.begin(), v.end(),sort_rule);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ':' << v[i].second << endl;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> v{1, 2, 3, 4};
    int n1 = 3;
    int n2 = 5;
    auto is_even = [](int i)
    { return i % 2 == 0; };

    std::vector<int>::iterator iter = std::find(begin(v), end(v), n1);
    auto result1 = std::find(begin(v), end(v), n1);
    auto result2 = std::find(begin(v), end(v), n2);
    auto result3 = std::find_if(begin(v), end(v), is_even);

    std::cout << *iter << std::endl;

    (result1 != std::end(v))
        ? std::cout << "v contains " << n1 << '\n'
        : std::cout << "v does not contain " << n1 << '\n';

    (result2 != std::end(v))
        ? std::cout << "v contains " << n2 << '\n'
        : std::cout << "v does not contain " << n2 << '\n';

    (result3 != std::end(v))
        ? std::cout << "v contains an even number: " << *result3 << '\n'
        : std::cout << "v does not contain even numbers\n";
}
//////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, string> m; //pair <string,string> 보관

    // 1.요소 넣기
    // 1_1. pair 만들어서 넣기
    pair<string, string> p("mon", "월요일");
    m.insert(p);

    // 1_2. make_pair => pair를 만들어 달라는 함수
    m.insert(make_pair("tue", "화요일"));

    // 1_3. emplace
    //이거하니깐 또 emplace사용시 안들어가지고 처음것이 유지되는 듯
    m.emplace("wed", "수요일");

    // 1_4. [] 연산자 사용 =>key 값으로 value 를 저장=> 가장 널리 사용
    m["thu"] = "목요일";

    //2.맵 객체 생성,초기화 가능
    map<string, string> m1 = {{"mon", "월요일"}, {"tue", "화요일"}};

    //3.[ ] 연산에 대해서
    string data = m1["mon"]; //data = "월요일" 이라는 뜻
    m1["mon"] = "월";        //변경도 가능

    // [] 연산자 => map이름["키값"]을 넣으면 second 즉,data가 나온다.
    cout << m1["sun"] << endl;
}

//////////////////////////////////////////////////////////////////////////
//map 인자 출력
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> m = {{"mon", 1}, {"tue", 2}};
    //1.원래 반복자를 사용해야한다.
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << it->second << '\n';

    //2.범위기반은 포인터다, auto로 쉽게 해결가능하다
    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << ' ' << iter->second << '\n';

    //3.index기반은 멤버데이터
    //iter->first하면 error
    for (auto iter : m)
    {
        cout << iter.first << " " << iter.second << endl;
    }
    for (auto &iter : m)
    {
        cout << iter.first << " " << iter.second << endl;
    }
}