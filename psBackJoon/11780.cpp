#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

vector<vector<int>> v(102, vector<int>(102, INF));
vector<vector<int>> route(102, vector<int>(102));
vector<int> ans;
int n, m, a, b, c;

void getRoute(int s, int e) {
  if (route[s][e] == 0) {
    ans.push_back(s);
    ans.push_back(e);
    return;
  }

  getRoute(s, route[s][e]);
  ans.pop_back();
  getRoute(route[s][e], e);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    v[a][b] = min(v[a][b], c);
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k<= n; ++k) {
        if (j == k) continue;
        if (v[j][i] + v[i][k] < v[j][k]) {
          v[j][k] = v[j][i] + v[i][k];
          route[j][k] = i;
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (v[i][j] == INF) cout << 0 << " ";
      else cout << v[i][j] << " ";
    }

    cout << '\n';
  }

  for (int i = 1; i<= n; ++i) {
    for (int j = 1; j<= n; ++j) {
      if (v[i][j] == INF) cout << 0;
      else {
        ans.clear();
        getRoute(i, j);
        cout << ans.size() << " ";
        for (auto ansi : ans) cout << ansi << " ";
      }

      cout << '\n';
    }
  }

  return 0;
}
