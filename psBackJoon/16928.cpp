#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int

using namespace std;

vector<int> v(101, -1);
vector<int> ls(101);
queue<int> q;

int n, m, x, y, cur, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    ls[x] = y;
  }

  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    ls[x] = y;
  }

  v[1] = 0;
  q.push(1);

  while(!q.empty()) {
    cur = q.front();
    q.pop();
    for (int i = 1; i <= 6; ++i) {
      t = cur + i;
      if (t > 100) continue;

      if (ls[t] != 0) {
        // ladder or snake -> 이동해야함
        t = ls[t];
      }
      if (v[t] == -1) {
        v[t] = v[cur]+1;
        q.push(t);
      }
    }
  }

  cout << v[100] << '\n';

  return 0;
}
