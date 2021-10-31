#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    multimap<int, char> mm;
    multimap<int, char>::iterator mmit;
    mm.insert(pair<int, char>(1, 'a')); //insert key 1, value 'a'
    mm.insert(pair<int, char>(2, 'b')); //insert key 2, value 'b'
    mm.insert(pair<int, char>(3, 'c')); //insert key 3, value 'c'
    mm.insert(pair<int, char>(4, 'd')); //insert key 4, value 'd'
    mm.insert(pair<int, char>(3, 'e')); //insert key 3, value 'e' > Allow!

    cout << "mm.erase(1)" << endl;
    mm.erase(1);                                                   //key가 1인값 제거
    cout << "mm.size : " << mm.size() << endl;                     //크기
    cout << "mm.max_size : " << mm.max_size() << endl;             //최대 사이즈
    cout << "mm.count(3) : " << mm.count(3) << endl;               //key가 3인 원소 갯수
    cout << "mm.find(2)->second : " << mm.find(2)->second << endl; //key가 2인 원소 value
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//출력에 관하여
//먼저 key에 해당하는 key출력
#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    multimap<int, string> mm;

    mm.insert(pair<int, string>(60, "C"));
    mm.insert(pair<int, string>(30, "C++"));
    mm.insert(pair<int, string>(40, "Linux"));
    mm.insert(pair<int, string>(70, "JAVA"));
    mm.insert(pair<int, string>(40, "Ubuntu"));
    mm.insert(pair<int, string>(90, "Unix"));
    mm.insert(pair<int, string>(40, "CentOS"));

    multimap<int, string>::iterator iter;
    //전부다 나열
    for (iter = mm.begin(); iter != mm.end(); iter++)
    {
        cout << "[" << iter->first << ", " << iter->second << "] ";
    }
    cout << "\n\n";

    /*
    lower_bound(key) 
    key 값에 해당하는 첫번째 원소의 iterator를 반환
    upper_bound(key) 
    key 값에 해당하는 마지막 원소의 다음 원소의 iterator를 반환
    */

    //중복 키 값이 존재하는 40 의 인자 출력.
    for (iter = mm.lower_bound(40); iter != mm.upper_bound(40); iter++)
    {
        cout << "[" << iter->first << ", " << iter->second << "] ";
    }
    cout << endl;
    /*
    인자 >= lower_bound
    인자 < upper_bound
    [ lower_iter, upper_bound )  개폐구간.
    */
    multimap<int, string>::iterator lower_iter = mm.lower_bound(40);
    multimap<int, string>::iterator upper_iter = mm.upper_bound(40);

    cout << "lower_iter : " << lower_iter->first << ", " << lower_iter->second << endl;
    cout << "upper_iter : " << upper_iter->first << ", " << upper_iter->second << endl;

    /*
    40이 key인 인자는 : [40, Linux] [40, Ubuntu] [40, CentOS]
    출력값은
    lower_iter : 40, Linux
    upper_iter : 60, C
    lower_bound(40)하면 key가 40인 pair중 가장 처음의 값을 출력
    upper_bound(40)하면 key가 40인 pair중 가장 마지막 다음 것 출력
    */

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//하나더!!
/*
equal_range(key)
key 값에 해당하는 원소들의 범위를 pair 객체로 반환합니다.
pair 객체의 first에는 첫번째로 나타나는 원소의 iterator가
second에는 마지막으로 나타나는 원소의 다음 원소의 iterator가 저장 되어 있습니다. 
즉 pair객체에는 lower_bound와 upper_bound가 저장 되어있습니다. 
*/

#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    multimap<int, int> mm;

    mm.insert(make_pair(1, 2));
    mm.insert(make_pair(1, 3));
    mm.insert(make_pair(2, 4));
    mm.insert(make_pair(3, 5));
    mm.insert(make_pair(3, 6));
    mm.insert(make_pair(3, 7));
    mm.insert(make_pair(4, 8));

    /*
    equal_range(key)
    key 값에 해당하는 원소들의 범위를 pair 객체로 반환합니다.
    key가 3인 pair들을 반환하는 개념
    */
    //key 값이 3인 원소 출력
    multimap<int, int>::iterator iter;
    for (iter = mm.equal_range(3).first; iter != mm.equal_range(3).second; iter++)
        cout << '[' << iter->first << ',' << iter->second << ']' << endl;

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//1.value 삭제

#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    multimap<int, int> mm;

    mm.insert(make_pair(1, 2));
    mm.insert(make_pair(2, 3));
    mm.insert(make_pair(3, 4));
    mm.insert(make_pair(3, 5));
    mm.insert(make_pair(4, 6));
    /*
    equal_range(key)
    key 값에 해당하는 원소들의 범위를 pair 객체로 반환합니다.
    key가 3인 pair들을 반환하는 개념
    */
    for (auto it = mm.equal_range(3).first; it != mm.equal_range(3).second; it++)
    {
        if (it->second == 5)
        {
            mm.erase(it);
        }
    }

    for (auto iter = mm.begin(); iter != mm.end(); iter++)
    {
        cout << "[" << iter->first << ", " << iter->second << "] ";
    }

    return 0;
}

//2.value 삭제////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    multimap<char, int> mymap;

    mymap.insert(pair<char, int>('a', 10));
    mymap.insert(pair<char, int>('b', 15));
    mymap.insert(pair<char, int>('b', 20));
    mymap.insert(pair<char, int>('c', 25));
    cout << "Print Everything\n";

    multimap<char, int>::iterator iter;
    for (iter = mymap.begin(); iter != mymap.end(); iter++)
    {
        cout << "[" << iter->first << ", " << iter->second << "] ";
    }
    cout << "\n\n";

    /*
    key가 'b'인 객체반환
    equal_range(key)
    key 값에 해당하는 원소들의 범위를 pair 객체로 반환합니다.
    */

    /*
    typedef multimap<char, int>::iterator iterator;
    std::pair<iterator, iterator> iterpair = mymap.equal_range('b');
   */
    std::pair<multimap<char, int>::iterator, multimap<char, int>::iterator> iter_pair = mymap.equal_range('b');
    multimap<char, int>::iterator it = iter_pair.first;

    cout << "Erase (b,15) pair" << endl;
    for (; it != iter_pair.second;)
    {
        if (it->second == 15)
        {
            it = mymap.erase(it);
        }
        else
            ++it;
    }

    for (auto iter = mymap.begin(); iter != mymap.end(); iter++)
    {
        cout << "[" << iter->first << ", " << iter->second << "] ";
    }
}