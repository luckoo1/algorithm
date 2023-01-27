/*
이런형식으로 더해야함
string temp_str = "";

string a = "abc";
temp_str+="abc"

char b = 'a'
temp_str.push_back(b);
*/

// 1-------------------------------------------
#include <stdio.h>

int main()
{
    char c1 = 'A'; //65
    //문자가 아닌 "문자열"을 보관하려면 char 타입의 배열을 사용 
    char s1[4] = {65, 66, 67, 68};
    char s2[4] = {'A', 'B', 'C', 'D'};

    printf("%d\n", s1[0]); //65
    printf("%c\n", s1[0]); //A

    printf("%c%c%c%c\n", s1[0], s1[1], s1[2], s1[3]);

    //배열의 이름은 배열의 첫번째 요소의 주소
    printf("%d\n", s1);//주소를 10진수로 출력
    printf("%p\n", s1);//주소를 16진수로 출력
    printf("%s\n", s1); // ABCDAa

    //%s의 의미는 주소에 있는 정수값들(아스키 코드)을 문자로 계속 출력
}

//2-------------------------------------------
#include <stdio.h>

int main()
{
    char s1[4] = {'A', 'B', 'C', 'D'};

    printf("%s\n", s1); // ABCDAa
    //a는 뭐지??
    //문자열의 끝이 어딘지 몰라서 쓰레기값이 계속 나오는거다.
}

#include <stdio.h>

int main()
{
    char s1[5] = {'A', 'B', 'C', 'D','\0'};
    char s2[5] = {'A', 'B', 'C', 'D', 0};
    //null문자로 문자열의 끝을 알려주자
    printf("%s\n", s1); // ABCDA
}
// 3-------------------------------------------
#include <stdio.h>

int main()
{
    //3가지는 같은거다
    char s1[5] = {'A', 'B', 'C', 'D', '\0'};
    char s2[5] = {'A', 'B', 'C', 'D', '\0'};
    char s3[] = {'A', 'B', 'C', 'D'};

    printf("%d\n", sizeof(s3));//자동으로 5를 잡아준다.
}
// 4-------------------------------------------
/*
'A' VS "A"
'A' : 문자 'A'의 아스키 코드 값(65)
"A" : 문자열 char 2개짜리 배열을 메모리의 할당
      배열의 첫번째 요소의 주소를 의미
      2칸배열에 'A'와 '\0'으로 채운것
*/
#include <stdio.h>

int main()
{
    printf("%d\n", 'A'); //65
    printf("%d\n", "A"); //주소를 10진수 출력
}
/*
"%c" VS "%s"
printf("%c\n", 아스키코드); : 아스키코드에 해당하는 문자 출력
printf("%c\n", 메모리주소); : 메모리 주소에 있는 값을 아스키 코드로 취급해서 문자출력
                              NULL문자를 만날때 까지 계속 출력
*/
#include <stdio.h>

int main()
{
    printf("%c\n", 'A'); //A
    printf("%c\n", "A"); //주소(0x12ff78)을 아스키코드로 해석
                         //엉뚱한 값이 출력

    printf("%s\n", 'A'); //65를 주소로 해석해서 65번지로 감->runtime error
    printf("%s\n", "A"); // 2칸배열에 'A'와 '\0'으로 채운것
                         // 이 배열로 가서 출력
}