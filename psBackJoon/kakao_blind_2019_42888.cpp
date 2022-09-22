// https://school.programmers.co.kr/learn/courses/30/lessons/42888

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


vector<string> solution(vector<string> record) {
  vector<string> answer;
  unordered_map<string, string> uidToName;
  vector<pair<string, bool>> uidLog;

  string name = "";
  string uid = "";
  char c = ' ';

  for (auto ri : record) {
    c = ri[0];
    auto iter = find(ri.begin(), ri.end(), ' ');
    auto iter2 = find(iter + 1, ri.end(), ' ');
    uid = ri.substr(iter + 1 - ri.begin(), iter2 - iter - 1);

    if (c == 'E') {
      uidToName[uid] = ri.substr(iter2 + 1-ri.begin(), ri.end() - iter2);
      uidLog.push_back({uid, true});
    } else if (c == 'L') {
      uidLog.push_back({uid, false});
    } else if (c == 'C') {
      uidToName[uid] = ri.substr(iter2 + 1 - ri.begin(), ri.end() - iter2);
    }
  }

  for (auto li : uidLog) {
    if (li.second) answer.push_back(uidToName[li.first] + "님이 들어왔습니다.");
    else answer.push_back(uidToName[li.first] + "님이 나갔습니다.");
  }
  return answer;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> a = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
  auto v = solution(a);
  for (auto vi : v) {
    cout << vi << ' ';
  }

  return 0;
}