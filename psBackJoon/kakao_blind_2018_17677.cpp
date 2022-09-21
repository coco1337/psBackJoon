// https://school.programmers.co.kr/learn/courses/30/lessons/17677

#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;


bool CheckChar(char c) {
  return c >= 'a' && c <= 'z';
}

int solution(string str1, string str2) {
  unordered_map<string, pair<int, int>> m;
  auto start = str1.begin();
  auto end = str1.begin() + 1;
  char t1, t2;

  while (end != str1.end()) {
    string t = "";
    t1 = tolower(*start);
    t2 = tolower(*end);
    if (CheckChar(t1) && CheckChar(t2)) {
      t += t1;
      t += t2;
      if (m.find(t) != m.end()) ++m[t].first;
      else m[t] = {1, 0};
    }
    ++start;
    ++end;
  }

  start = str2.begin();
  end = str2.begin() + 1;
  while (end != str2.end()) {
    string t = "";
    t1 = tolower(*start);
    t2 = tolower(*end);
    if (CheckChar(t1) && CheckChar(t2)) {
      t += t1;
      t += t2;
      if (m.find(t) != m.end()) ++m[t].second;
      else m[t] = {0, 1};
    }
    ++start;
    ++end;
  }

  int a = 0, b = 0;
  for (auto mi : m) {
    a += min(mi.second.first, mi.second.second);
    b += max(mi.second.first, mi.second.second);
  }

    if (b == 0) return 65536;
  return floor(((double)a/b) * 65536);
}