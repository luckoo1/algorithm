/*
lower_bound(key) 
key 값에 해당하는 첫번째 원소의 iterator를 반환합니다. 

upper_bound(key) 
key 값에 해당하는 마지막 원소의 다음 원소의 iterator를 반환합니다. 

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

    //lower_bound 는 3,5의 iterator를 upper_bound 는 3,7의 다음인 4,8의 iterator를 반환합니다.
    for (auto it = mm.lower_bound(3); it != mm.upper_bound(3); it++) //key 값이 3인 원소 출력
        cout << '[' << it->first << ',' << it->second << ']' << endl;

    for (auto it = mm.equal_range(3).first; it != mm.equal_range(3).second; it++) //key 값이 3인 원소 출력
        cout << '[' << it->first << ',' << it->second << ']' << endl;

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
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

    for (mmit = mm.begin(); mmit != mm.end(); mmit++)
    {
        cout << "key값 : " << mmit->first;              //iterator->first는 key
        cout << ", value값 : " << mmit->second << endl; //iterator->second는 value
    }

    cout << "mm.erase(1) 수행" << endl;
    mm.erase(1); //key가 1인값 제거

    for (mmit = mm.begin(); mmit != mm.end(); mmit++)
    {
        cout << "key값 : " << mmit->first;              //iterator->first는 key
        cout << ", value값 : " << mmit->second << endl; //iterator->second는 value
    }

    cout << "mm.size : " << mm.size() << endl;                     //크기
    cout << "mm.max_size : " << mm.max_size() << endl;             //최대 사이즈
    cout << "mm.count(3) : " << mm.count(3) << "개" << endl;       //key가 3인 원소 갯수
    cout << "mm.find(2)->second : " << mm.find(2)->second << endl; //key가 2인 원소 value
    cout << "mm.lower_bound(3) : " << mm.lower_bound(3)->first << ", " << mm.lower_bound(3)->second << endl;
    cout << "mm.upper_bound(3) : " << mm.upper_bound(3)->first << ", " << mm.upper_bound(3)->second << endl;

    return 0;
}