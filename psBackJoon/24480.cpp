#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long int

using namespace std;

vector<vector<int>> v(100'001, vector<int>());
vector<int> c(100'001);
int n, m, r, p, q;
int cnt;

void dfs(int t){
  c[t] = ++cnt;

  for (auto vti : v[t]) {
    if (c[vti] == 0) dfs(vti);
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

  for (int i = 1; i <= n; ++i) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }

  dfs(r);

  for (int i = 1; i <= n; ++i) {
    cout << c[i] << '\n';
  }

  return 0;
}
