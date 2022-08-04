#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f
#define MAX 100000

using namespace std;

vector<int> v(MAX + 1, INF);
int n, k;
deque<int> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  dq.push_back(n);
  v[n] = 0;

  while (!dq.empty()) {
    int x = dq.front();
    dq.pop_front();

    if (x == k) break;

    if (x * 2 <= MAX && v[x * 2] == INF) {
      dq.push_front(x * 2);
      v[x * 2] = v[x];
    }

    if (x + 1 <= MAX && v[x + 1] == INF) {
      dq.push_back(x + 1);
      v[x + 1] = v[x] + 1;
    }

    if (x - 1 >= 0 && v[x - 1] == INF) {
      dq.push_back(x - 1);
      v[x - 1] = v[x] + 1;
    }
  }

  cout << v[k];

  return 0;
}
