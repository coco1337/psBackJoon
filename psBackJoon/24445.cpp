#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int

using namespace std;

int n, m, r, p, q;
int cnt;

vector<vector<int>> v(100'001, vector<int>());
vector<int> c(100'001);
queue<int> qu;

void bfs(int t){

  c[t] = ++cnt;
  qu.push(t);

  while(!qu.empty()) {
    int u = qu.front();
    qu.pop();

    for (auto vui: v[u]) {
      if (c[vui] == 0) {
        c[vui] = ++cnt;
        qu.push(vui);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> r;

  for (int i = 0; i < m; ++i) {
    cin >> p >> q;
    v[p].push_back(q);
    v[q].push_back(p);
  }

  for (int i = 1; i <= n; ++i)
    sort(v[i].begin(), v[i].end(),greater<int>());

  bfs(r);

  for (int i = 1; i <= n; ++i)
    cout << c[i] << '\n';

  return 0;
}
