#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int n;
int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n * n; ++i) {
    cin >> t;
    pq.push(t);
    if (pq.size() > n)
      pq.pop();
  }

  cout << pq.top();

  return 0;
}