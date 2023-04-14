// sort()함수를 이용
#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

int main(void)
{
    int data[10] = {9, 3, 5, 7, 8, 1, 2, 4, 6, 10};
    sort(data, data + 10);
    // 배열과 마지막원소를 넣어준다.
    for (int i = 0; i < 10; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;

    // greater 함수를 이용해서 내림차순으로 표현할 수 있다.
    sort(data, data + 10, desc);
    for (int i = 0; i < 10; i++)
    {
        cout << data[i] << ' ';
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sort_rule(pair<int, string> a,pair<int, string> b)
{
    return a.second > b.second;
}

int main(void)
{
    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(99, "a"));
    v.push_back(pair<int, string>(79, "b"));
    v.push_back(pair<int, string>(80, "c"));
    v.push_back(pair<int, string>(88, "d"));
    v.push_back(pair<int, string>(92, "e"));
    v.push_back(pair<int, string>(84, "f"));
    v.push_back(pair<int, string>(97, "g"));
    v.push_back(pair<int, string>(82, "h"));
    v.push_back(pair<int, string>(90, "i"));
    sort(v.begin(), v.end(),sort_rule);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ':' << v[i].second << endl;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
// sort()를 이용하여 학생점수 오름차순으로 나열하기

#include <iostream>
#include <algorithm>
using namespace std;
class Student
{
public:
    string name;
    int score;
    // constructor
    Student(string name, int score)
    {
        this->name = name;
        this->score = score;
    } // operator '<' overloading
    bool operator<(Student &student) { return this->score < student.score; }
};
int main(void)
{
    Student students[] = {
        Student("a", 99), Student("e", 79),
        Student("b", 80), Student("f", 88),
        Student("c", 92), Student("g", 84),
        Student("d", 97), Student("h", 82)};
    sort(students, students + 9);
    for (int i = 0; i < 9; i++)
    {
        cout << students[i].name << " : " << students[i].score << endl;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
// class없이 pair사용하기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(99, "a"));
    v.push_back(pair<int, string>(79, "b"));
    v.push_back(pair<int, string>(80, "c"));
    v.push_back(pair<int, string>(88, "d"));
    v.push_back(pair<int, string>(92, "e"));
    v.push_back(pair<int, string>(84, "f"));
    v.push_back(pair<int, string>(97, "g"));
    v.push_back(pair<int, string>(82, "h"));
    v.push_back(pair<int, string>(90, "i"));
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << ':' << v[i].first << endl;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
    {
        // 점수가 동일할때는 생년월일이 느린사람(높은사람)순으로 정렬
        return a.second.second > b.second.second;
    }
    else
    { // 점수 내림차순
        return a.second.first > b.second.first;
    }
}
int main(void)
{
    vector<pair<string, pair<int, int>>> v;
    v.push_back(pair<string, pair<int, int>>("a", make_pair(90, 19910329)));
    v.push_back(pair<string, pair<int, int>>("b", make_pair(98, 19990305)));
    v.push_back(pair<string, pair<int, int>>("c", make_pair(92, 19940210)));
    v.push_back(pair<string, pair<int, int>>("d", make_pair(94, 19960903)));
    v.push_back(pair<string, pair<int, int>>("e", make_pair(94, 19940221)));
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < 5; i++)
    {
        cout << v[i].first << '(' << v[i].second.second;
        cout << "):" << v[i].second.first << endl;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int parent[101];

bool sort_rule(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find_parent(int node)
{
    if (parent[node] == node)
        return node;

    return find_parent(parent[node]);
}

int solution(int n, vector<vector<int>> costs)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(costs.begin(), costs.end(), sort_rule);

    for (int i = 0; i < costs.size(); i++)
    {
        int start = find_parent(costs[i][0]);
        int end = find_parent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end)
        {
            ans += cost;
            parent[end] = start;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> a{{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};
    int b = 4;
    int ans = solution(b, a);
    cout << endl;
    cout << ans;
}