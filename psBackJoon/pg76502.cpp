// https://school.programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solve(string s) {
    int c1 = 0, c2 = 0, c3 = 0;
    stack<char> st;
    for (auto si : s) {
        if (si == '(' || si == '{' || si == '[') st.push(si);
        else {
            if (st.empty()) return 0;
            
            if (si == ')' && st.top() == '(') st.pop();
            else if (si == '}' && st.top() == '{') st.pop();
            else if (si == ']' && st.top() == '[') st.pop();
            else return 0;
        }
    }
    
    return 1;
}

int solution(string s) {
    int answer = 0;
    if (s.size() % 2 == 1) return 0;
    for (int i = 0; i < s.size(); ++i) {
        string tmp(s.begin() + i, s.end());
        tmp += s.substr(0, i);
        answer += solve(tmp);
    }
    return answer;
}