//////////////////////////////////////////////////////////////////////////
//2차원 초기화방식 1
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vect;

int main()
{

    vector<vector<int>> vect{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[0].size(); j++)
        {
            printf("%d ", vect[i][j]);
        }
        printf("\n");
    }
}
//////////////////////////////////////////////////////////////////////////
//1. 2차원 초기화방식 2
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> v1;

int main()
{

    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(3);

    v.push_back(v1);
    v1.erase(v1.begin(), v1.end());

    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v.push_back(v1);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

//////////////////////////////////////////////////////////////////////////
//3. 2차원 초기화방식 2
#include <iostream>
#include <vector>
using namespace std;

vector<int> v(5);                             //0이 5개
vector<int> v1(5, 2);                         //2가 5개
vector<vector<int>> v2(4, vector<int>(5));    //0이 5개 들어간 vector가 4개
vector<vector<int>> v3(4, vector<int>(5, 3)); //3이 5개 들어간 vector가 4개

int main()
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    for (int i = 0; i < v1.size(); i++)
    {
        printf("%d ", v1[i]);
    }
    printf("\n\n");

    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[0].size(); j++)
        {
            printf("%d ", v2[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for (int i = 0; i < v3.size(); i++)
    {
        for (int j = 0; j < v3[0].size(); j++)
        {
            printf("%d ", v3[i][j]);
        }
        printf("\n");
    }
}

//////////////////////////////////////////////////////////////////////////
//원소제거하기
//pop_back()은 기본
#include <iostream>
#include <vector>
using namespace std;

vector<int> v{1, 2, 3, 4, 5};
vector<int> v1{1, 2, 3, 4, 5};
vector<int> v2{1, 2, 3, 4, 5};

int main()
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    v.erase(v.begin()); //맨 앞에것만
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    v1.erase(v1.begin() + 1); //2번째 것만 삭제
    for (int i = 0; i < v1.size(); i++)
    {
        printf("%d ", v1[i]);
    }
    printf("\n\n");

    v2.erase(v2.begin() + 1, v2.begin() + 3); //2번째부터 4번째까지 삭제
    for (int i = 0; i < v2.size(); i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n\n");

    printf("%d\n", v2.size()); //size도 변경된다.

    v.clear(); //다 삭제
}
//////////////////////////////////////////////////////////////////////////
//원소삽입하기
//push_back()은 기본
#include <iostream>
#include <vector>
using namespace std;

vector<int> v{1, 2, 3, 4, 5};
vector<int> v1{1, 2, 3, 4, 5};

int main()
{
    v.insert(v.begin() + 1, 99); //1번째에 99삽입

    v1.insert(v1.begin() + 1, 3, 4); //1 4 4 4 2 3 4 5
    //1번째에 4를 3개 삽입

    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
}
//////////////////////////////////////////////////////////////////////////
//원소정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v{4, 3, 2, 1, 5};

int main()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
}
//////////////////////////////////////////////////////////////////////////
//원소반대로 나열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v{4, 3, 2, 1, 5};

int main()
{
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
}