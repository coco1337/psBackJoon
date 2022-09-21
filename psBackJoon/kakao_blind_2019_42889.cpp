// https://school.programmers.co.kr/learn/courses/30/lessons/42889#

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<double, int> a, pair<double, int> b){
      if (a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    }
};

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;
  sort(stages.begin(), stages.end());

  auto end = stages.begin();
  auto start = stages.begin();
  for (int i = 1; i <= N; ++i) {
    end = upper_bound(stages.begin(), stages.end(), i);
    start = lower_bound(stages.begin(), stages.end(), i);
    auto fail = (start == stages.end() ? 0 : ((double)(end - start) / (stages.size() - (start - stages.begin()))));
    pq.push({fail, i});
  }

  while(!pq.empty()) {
    answer.push_back(pq.top().second);
    pq.pop();
  }

  return answer;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 4;
  vector<int> st = {1,1,1,1,1};
  auto ans = solution(n, st);
  for (auto ansi: ans) {
    cout << ansi << ' ';
  }

  return 0;
}