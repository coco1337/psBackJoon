// https://school.programmers.co.kr/learn/courses/30/lessons/17684

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;
  vector<string> dictIdx(1);
  unordered_map<string, int> m;

  for (char i = 'A'; i <= 'Z'; ++i){
    string s = "";
    s += i;
    dictIdx.push_back(s);
    m.insert({s, i - 'A' + 1});
  }

  int idx = 0;
  string t = "";

  while (true) {
    if (idx == msg.size()) break;
    t += msg[idx];
    if (m.contains(t)) {
      ++idx;
      continue;
    } else {
      dictIdx.push_back(t);
      m.insert({t, dictIdx.size() - 1});
      answer.push_back(m[t.substr(0, t.size() - 1)]);
      t = "";
    }
  }

  if (t != "") {
    if (m.contains(t)) {
      answer.push_back(m[t]);
    }
  }
  return answer;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a = "ABABABABABABABAB";
  auto v = solution(a);
  for (auto vi : v) {
    cout << vi << ' ';
  }

  return 0;
}