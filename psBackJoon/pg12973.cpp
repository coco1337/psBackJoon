// https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
  for (int i = 0; i < s.size(); ++i) {
    if (st.empty()) {
      st.push(s[i]);
      continue;
    }
    auto t = st.top();
    if (t == s[i]) st.pop();
    else st.push(s[i]);
  }
    
    return st.empty() ? 1 : 0;
}