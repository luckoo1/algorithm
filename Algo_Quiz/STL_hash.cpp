#include <iostream>
int main()
{
    //STL의 해쉬함수는 함수객체로 되어 있다.
    std::hash<int> hi;
    std::hash<double> hd;
    std::hash<std::string> hs;

    //100을 저장하고 싶다.
    //몇번 버킷(bucket,케비넷)에 저장할지 "해쉬함수"에 물어본다.
    int n1 = hi(100); //100을 어디에 저장할지, 저장할 장소를 n1에 저장
    //예를  들어서 => 나온 값(n1) % 버켓크기(갯수) = 저장할 버킷 index

    std::cout << n1 << std::endl;

    std::cout << hi(300) << std::endl;
    std::cout << hi(200) << std::endl;
    std::cout << hi(733) << std::endl;

    std::cout << hs("hello") << std::endl;
    std::cout << hs("AAAA") << std::endl;

    //200을 찾고 싶다..
    //200이 몇번째 bucket에 있는지 알아낸다.
    std::cout << hi(200) << std::endl;
}
