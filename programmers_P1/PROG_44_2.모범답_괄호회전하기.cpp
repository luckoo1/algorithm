#include <string>
#include <vector>
#include <stack>
using namespace std;

string rotate(string str) {
    string res = str;
    char tmp = res[0];
    res.erase(0, 1);
    res.push_back(tmp);
    return res;
}

bool isCorrect(string str) {
    stack<char> st;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else {
            if(st.empty()) return false;
            else {
                if(st.top() == '(' && str[i] == ')') st.pop();
                else if(st.top() == '{' && str[i] == '}') st.pop();
                else if(st.top() == '[' && str[i] == ']') st.pop();
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    if(isCorrect(s)) answer++; 
    for(int i = 1; i < s.size(); i++) {
        s = rotate(s);
        if(isCorrect(s)) answer++;
    }
    return answer;
}