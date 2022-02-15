#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> hash_map;

    for (int i = 0; i < phone_book.size(); i++) //해쉬맵에 key로 번호를 다 넣었다.
        hash_map[phone_book[i]] = 1;
    //key : phone_book[i]
    //data : 1

    for (int i = 0; i < phone_book.size(); i++) //book에 번호를 하나씩 꺼내서
    {
        string number = "";
        for (int j = 0; j < phone_book[i].size(); j++) //j는 phone_book[i]의 글자수 탐색
        {
            number += phone_book[i][j]; //phone_number의 글자수대로 넣어보면서

            if (hash_map[number] == 1)       //hash에 key가 있고
                if (number != phone_book[i]) //글자수대로 넣어본거랑 phone_book[i]랑 다르면
                    return false;
            //vector<string> c = {"12", "34", "123", "1235", "567", "88"};
            //"123"이었는데 string number에 123의 한글자씩 추가하다가
            //두글자만 추가한 "12"면 hash_map["12"]==1이고
            //"12 != 123"이므로 return false
        }
    }
    return true;
}

int main()
{
    vector<string> a = {"4321", "432"};
    vector<string> b = {"123", "124", "789"};
    vector<string> c = {"12", "34", "123", "1235", "567", "88"};
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    return 0;
}
