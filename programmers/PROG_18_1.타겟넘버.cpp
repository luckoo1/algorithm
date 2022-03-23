#include <string>
#include <vector>
using namespace std;

int answer = 0;

void DFS(int dep,int temp_ans,vector<int> &numbers, const int &target) {
    if(dep ==numbers.size()){
        if(temp_ans == target) 
        {
            answer++;
        }
        return;
    }

    DFS(dep+1,temp_ans+numbers[dep],numbers, target);
    DFS(dep+1,temp_ans-numbers[dep],numbers, target);
}

int solution(vector<int> numbers, int target) 
{

    DFS(0 ,0,numbers, target);

    return answer;
}