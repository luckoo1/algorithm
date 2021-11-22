//map 초기화
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

//-----------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------
//map 인자 찾기
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, string> m = {{"mon", "월요일"}, {"tue", "화요일"}};

    std::string s = m["sun"]; //1. m map에 "sun"이라는 key값은 없다. 에러는 안뜬다.
                              //2. {"sun",""}이라는 항목이 추가되고,data는 빈문자열 ""이 반환
    //즉, key값을 가지고 data를 검색할때는
    std::string s2 = m["sat"]; //무조건 성공이다... {"sat",""}를 만들기 때문에
                               //반환값은 빈 문자열
    //그래서 data를 검색할떄는 find를 써라

    auto p = m.find("wed");

    if (p == m.end())
    {
        std::cout << "serch fail" << std::endl;
    }
    else
    {
        std::cout << p->first << " : ";
        std::cout << p->second << std::endl;
    }

    auto p1 = m.find("mon");

    if (p1 == m.end())
    {
        std::cout << "serch fail" << std::endl;
    }
    else
    {
        std::cout << p1->first << " : ";
        std::cout << p1->second << std::endl;
    }
    //반복자 : 요소를 가리키는 포인터 역할의 객체
    //p는 map의 요소를 가리키는 반복자
    //map의 반복자 : "pair"를 가리키는 포인터로 생각
}
//-----------------------------------------------------------------------------------
//map 인자 삭제
/*
1. 특정 위치의 요소 삭제
m.erase(m.begin()+2);


2. key값을 기준으로 요소 삭제
m.erase("Alice");
 
3. map의 모든 요소 삭제
erase 함수로 모든 요소 삭제하기 (map의 begin부터 end까지)
m.erase(m.begin(), m.end());

4.찾아서 삭제
m.erase(m.find("f"));

*/
//해당key에 value삭제
#include <map>
#include <iostream>
int main()
{
    std::multimap<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}};

    // erase all odd numbers from c
    std::multimap<int, std::string>::iterator it;
    for (it = c.begin(); it != c.end();)
    {
        if (it->first % 2 != 0)
            it = c.erase(it);
        else
            ++it;
    }

    for (auto &p : c)
    {
        std::cout << p.second << ' ';
    }
}

//-----------------------------------------------------------------------------------
//하나의 key에 vector를 넣어서 여러 value넣기
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> ans;
    map<string, vector<int>> hash_map;

    for (int i = 0; i < genres.size(); i++)
    {
        hash_map[genres[i]].push_back(plays[i]);
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        cout << iter->first << endl;                  //iter->first는 string
        for (int i = 0; i < iter->second.size(); i++) //iter->second는 vector
        {
            cout << iter->second[i] << " ";
        }
        cout << endl;
    }

    return ans;
}

int main()
{
    vector<string> a{"classic", "pop", "classic", "classic", "pop"};
    vector<int> b{500, 600, 150, 800, 2500};

    vector<int> answer = solution(a, b);
    cout << "\n";
    for (auto n : answer)
        cout << n << endl;
}
//-----------------------------------------------------------------------------------
//key유무 확인
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    string key_to_find;
    std::map<string, string> lang_map = {
        {
            "j",
            "Julia",
        },
        {
            "p",
            "Python",
        },
        {
            "m",
            "MATLAB",
        },
        {
            "o",
            "Octave",
        },
        {
            "s",
            "Scala",
        },
        {
            "l",
            "Lua",
        }};

    for (const auto &[key, value] : lang_map)
    {
        cout << key << " : " << value << endl;
    }

    cout << "Enter the key to search for: ";
    cin >> key_to_find;

    if (lang_map.find(key_to_find) != lang_map.end())
    {
        cout << "Key Exists!" << endl;
    }

    return EXIT_SUCCESS;
}