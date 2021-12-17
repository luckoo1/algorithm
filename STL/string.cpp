//초기화
#include <iostream>
#include <string>
using namespace std;
int main()
{

    string s; //변수 선언

    string s = "Kang"; // output : Kang

    string s1("Kang");                 // output : Kang
    string s2(4, 'A');                 // output : AAAA
    string s3(s1, 0, s1.length() - 2); // output : HW
    string s4(s1, 2, s1.length());     // output : an
    string s5(s2);                     // output : AAAA
    string s6("ABCDE", 3);             // output : ABC

    char c[] = "TEST Code!!";
    string s7(c); // output : TEST Code!!
    /////////////////////////////////////////////////////////​
}

////////////////////////////////////////////////////////////////////////////////////////
// substr()

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "0123456789";

    string b = a.substr(0, 4);
    cout << b << endl;
    // 0123
    // 0번index로부터 4글자

    string c = a.substr(4);
    cout << c << endl;
    // 456789
    // 4번 index부터 끝까지

    string d = a.substr(8, 9999);
    cout << d << endl;
    // 8,9
    // 8번 index부터 끝까지

    string e = a.substr(11, 2);
    cout << e << endl;
    // error
}
////////////////////////////////////////////////////////////////////////////////////////
/*
find
반환값은 찾는 문자의 첫번째 인덱스값
찾는 문자가 없을 경우는 string::npos를 리턴한다.(npos는 no position으로 쓰레기값 나옴)
*/
#include <iostream>
#include <string>
using namespace std;

void print(std::string::size_type n, std::string const &s)
{
    if (n == std::string::npos)
    {
        std::cout << "not found\n";
    }
    else
    {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}

int main()
{
    std::string::size_type n;
    std::string const s = "This is a string";

    // search from beginning of string
    n = s.find("is");
    print(n, s);

    // search from position 5
    n = s.find("is", 5);
    print(n, s);

    // find a single character
    n = s.find('a');
    print(n, s);

    // find a single character
    n = s.find('q');
    print(n, s);
}