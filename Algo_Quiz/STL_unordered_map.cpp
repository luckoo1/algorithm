#include <iostream>
#include <string>
#include <unordered_map>
#include <typeinfo>
using namespace std;

int main()
{

    unordered_map<string, int> um;

    if (um.empty())
    {
        cout << "unordered_map is empty" << endl;
    }
    //초기화
    um.insert(make_pair("key", 1));
    um["banana"] = 2;
    um.insert({"melon", 3});
    um["apple"]; //key가 'apple'이고 값은 0으로 초기화

    cout << "unordered_map size " << um.size() << endl;
    cout << endl;

    //나열
    for (auto elem : um)
    {
        cout << "key : " << elem.first << " value : " << elem.second << endl;
    }
    cout << endl;
    //apple->melon->banana->key순으로 나열된다.

    //find 대신 count로 확인 가능
    if (um.find("banana") != um.end())
    {
        um.erase("banana");
    }

    cout << "unordered_map size " << um.size() << endl;
    for (auto elem : um)
    {
        cout << "key : " << elem.first << " value : " << elem.second << endl;
    }

    return 0;
}
