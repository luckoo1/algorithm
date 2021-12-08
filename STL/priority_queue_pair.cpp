#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print_queue(T q)
{ // NB: pass by value so the print uses a copy
    while (!q.empty())
    {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << '\n';
}

int main()
{
    priority_queue<int> q;

    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    priority_queue<int, vector<int>, greater<int>> q2(data.begin(), data.end());

    print_queue(q2);

    priority_queue<int, vector<int>, greater<int>> PQ1;

    for (int n : data)
        PQ1.push(n);

    print_queue(PQ1);

    //이런식으로 pair도 가능
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push(make_pair(1, 2));
}