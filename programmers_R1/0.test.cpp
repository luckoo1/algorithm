#include <queue>
#include <vector>
#include <iostream>
#include <functional>

 
 void print_q( std::priority_queue<int> q)
 {
    std::cout<<"PRINT"<<std::endl;
    int a = q.top();
    std::cout<<a<<std::endl;
    q.pop();

 }
int main()
{
 
    std::vector<int> vec={3, 1, 4, 1, 5};
    std::priority_queue<int,std::less<int>> c3(vec.begin(),vec.end());
    print_q(c3);

}