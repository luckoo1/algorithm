//https: //programmers.co.kr/learn/courses/30/lessons/42586

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    vector<int> v1{1, 30, 5};
    for (int i = 0; i < v1.size(); i++)
    {
        v1.erase(v1.begin());
    }
    printf("finish\n");
}