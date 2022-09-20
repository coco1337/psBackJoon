// https://school.programmers.co.kr/learn/courses/30/lessons/64065

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;
string s;

vector<vector<int>> vec(501);
int maxSize;

void AddVec(string t) {
  auto offset = t.begin();
  auto end = find(t.begin(), t.end(), ',');
  vector<int> tmp;
  while (true) {
    tmp.push_back(stoi(t.substr(offset - t.begin(), end - t.begin())));
    if (end == t.end()) break;
    offset = end + 1;
    end = find(offset, t.end(), ',');
  }

  sort(tmp.begin(), tmp.end());
  vec[tmp.size() - 1] = tmp;
  maxSize = maxSize > tmp.size() ? maxSize : tmp.size();
}

void MakeVector(string t){
  string tmp(t.begin() + 1, t.end() - 1);
  auto offset = find(tmp.begin(), tmp.end(), '{');
  auto end = find(offset, tmp.end(), '}');
  while (offset != tmp.end()) {
    AddVec(tmp.substr(offset - tmp.begin() + 1, end - offset - 1));
    offset = find(end,tmp.end(), '{');
    end = find(offset, tmp.end(), '}');
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  vector<int> answer;
  MakeVector(s);

  answer.push_back(vec[0][0]);

  for (int i = 0; i < maxSize - 1; ++i) {
    bool test = false;
    for (int j = 0; j < vec[i].size(); ++j) {
      if (vec[i][j] == vec[i + 1][j]) continue;
      else {
        answer.push_back(vec[i + 1][j]);
        test = true;
        break;
      }
    }
    if (!test) answer.push_back(vec[i + 1][vec[i+1].size() - 1]);
  }

  for (auto ai : answer) {
    cout << ai << ' ';
  }
  return 0;
}