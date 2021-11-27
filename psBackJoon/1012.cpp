#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long int

// https://www.acmicpc.net/problem/1012

using namespace std;

int t, m, n, k;
int x, y;
int cnt;

vector<vector<bool>> v;
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };
vector<vector<bool>> check;

void Dfs(int a, int b) {
  check[a][b] = true;
  for (int i = 0; i < 4; ++i) {
    int p = a + dx[i];
    int q = b + dy[i];

    if (p >= 0 && p < m && q >= 0 && q < n)
      if (!check[p][q] && v[p][q]) Dfs(p, q);
  }
}

void Solve() {
  cin >> m >> n >> k;
  cnt = 0;
  v.assign(51, vector<bool>(51, false));
  check.assign(51, vector<bool>(51, false));
  for (int i = 0; i < k; ++i) {
    cin >> x >> y;
    v[x][y] = true;
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!check[i][j] && v[i][j]) {
        Dfs(i, j);
        cnt++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;

  for (int i = 0; i < t; ++i) {
    Solve();
    cout << cnt << '\n';
  }

  return 0;
}
