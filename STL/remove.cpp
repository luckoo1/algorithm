//특정원소제거
#include <algorithm> // for std::remove
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    for (int i = 0; i < v.size(); i++)
        printf("%d--", v[i]);
    printf("\n");

    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
    v.erase(std::remove(v.begin(), v.end(), 4), v.end());

    for (int i = 0; i < v.size(); i++)
        printf("%d--", v[i]);
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////
#include <algorithm> // for std::remove
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    auto a = v.end() - 1;
    cout << *a << endl; //5나옴
    auto a = v.end();   //알수없는 주소값
    //이유는 v.end()는 5다음에 주소라서 그렇다.

    auto b = std::remove(v.begin(), v.end(), 2);

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    b = b - 2;
    cout << *b << endl;

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
}