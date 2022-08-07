#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

vector<vector<pair<int, int>>> v(501, vector<pair<int, int>>());
vector<ll> d(501, INF);
int n, m, a, b, c;

bool bf(int s) {
  d[s] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < v.size(); ++j) {
      for (int k = 0; k < v[j].size(); ++k) {
        if (d[j] != INF && d[v[j][k].first] > d[j]+ v[j][k].second) {
          d[v[j][k].first] = d[j] + v[j][k].second;
          if (i == n)
            return true;
        }
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    v[a].push_back({b, c});
  }

  if (bf(1)) {
    cout << -1;
    return 0;
  }

  for (int i = 2 ; i <= n; ++i){
    if (d[i] == INF) cout << "-1" << '\n';
    else cout << d[i] << '\n';
  }

  return 0;
}
