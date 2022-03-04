//////////////////////////////////////////////////////////////////////////
// 2차원 초기화방식 1
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
// 1. 2차원 초기화방식 2
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
// 3. 2차원 초기화방식 2
#include <iostream>
#include <vector>
using namespace std;

vector<int> v(5);                             // 0이 5개
vector<int> v1(5, 2);                         // 2가 5개
vector<vector<int>> v2(4, vector<int>(5));    // 0이 5개 들어간 vector가 4개
vector<vector<int>> v3(4, vector<int>(5, 3)); // 3이 5개 들어간 vector가 4개
vector<vector<int>> v4(4);                    // vector<int> 4개

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
// pop_back()은 기본
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

    v1.erase(v1.begin() + 1); // 2번째 것만 삭제
    for (int i = 0; i < v1.size(); i++)
    {
        printf("%d ", v1[i]);
    }
    printf("\n\n");

    v2.erase(v2.begin() + 1, v2.begin() + 3); // 2번째부터 4번째까지 삭제
    for (int i = 0; i < v2.size(); i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n\n");

    printf("%d\n", v2.size()); // size도 변경된다.

    v.clear(); //다 삭제
}
//////////////////////////////////////////////////////////////////////////
//원소삽입하기
// push_back()은 기본
#include <iostream>
#include <vector>
using namespace std;

vector<int> v{1, 2, 3, 4, 5};
vector<int> v1{1, 2, 3, 4, 5};

int main()
{
    v.insert(v.begin() + 1, 99); // 1번째에 99삽입

    v1.insert(v1.begin() + 1, 3, 4); // 1 4 4 4 2 3 4 5
    // 1번째에 4를 3개 삽입

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
//////////////////////////////////////////////////////////////////////////
// vector 복사
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a1{1, 5, 2, 6, 3, 7, 4};

    vector<int> ans = {a1.begin(), a1.begin() + 2};

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    vector<int> ans1 = {a1.begin(), a1.end()};

    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////
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
//가장 큰수나 작은수 찾기
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(46);
    v.push_back(68);
    v.push_back(184);
    v.push_back(4);
    v.push_back(17);
    v.push_back(53);

    cout << "현재 vector : ";
    for (int i : v)
        cout << i << " ";
    cout << "\n==============================\n";

    int max = *max_element(v.begin(), v.end());
    cout << "가장 큰 수 : " << max << "\n";

    int max_index = max_element(v.begin(), v.end()) - v.begin();
    cout << "가장 큰 수의 인덱스 : " << max_index;
    cout << "\n==============================\n";

    int min = *min_element(v.begin(), v.end());
    cout << "가장 작은 수 : " << min << "\n";

    int min_index = min_element(v.begin(), v.end()) - v.begin();
    cout << "가장 작은 수의 인덱스 : " << min_index << "\n\n";

    return 0;
}
//////////////////////////////////////////////////////////////////////////
//정책사용
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

static bool abs_compare(int a, int b)
{
    return (std::abs(a) < std::abs(b));
}

int main()
{
    std::vector<int> v{3, 1, -14, 1, 5, 9};
    std::vector<int>::iterator result;

    result = std::max_element(v.begin(), v.end());
    std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';

    result = std::max_element(v.begin(), v.end(), abs_compare);
    std::cout << "max element (absolute) at: " << std::distance(v.begin(), result) << '\n';
}
/////////////////////////////////////////////////////////////////////////////////