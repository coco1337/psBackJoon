#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int v, e, a, b, c;
vector<vector<int>> m(401, vector<int>(401, INF));
int ans = INF;

// 플로이드 마샬
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v >> e;

  for (int i = 0; i < e; ++i) {
    cin >> a >> b >> c;
    m[a][b] = c;
  }

  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= v; ++j) {
      for (int k = 1; k <= v; ++k) {
        m[j][k] = min(m[j][i] + m[i][k], m[j][k]);
        if (j == k) ans = min(ans, m[j][k]);
      }
    }
  }

  cout << (ans == INF ? -1 : ans);

  return 0;
}
