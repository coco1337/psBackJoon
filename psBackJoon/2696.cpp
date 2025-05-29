#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

int t;
int n;
int x;

void solve() {
  cin >> n;

  priority_queue<int> lq;
  priority_queue<int, vector<int>, greater<int> > rq;
  vector<int> v;

  for (int i = 1; i <= n; ++i) {
    cin >> x;

    if (i % 2 != 0) {
      rq.push(x);

      if (!lq.empty() && !rq.empty() && rq.top() < lq.top()) {
        rq.push(lq.top());
        lq.pop();
        lq.push(rq.top());
        rq.pop();
      }

      v.push_back(rq.top());
    } else {
      lq.push(x);
    }
  }

  cout << v.size() << '\n';
  for (auto vi : v){
    cout << vi << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

  return 0;
}