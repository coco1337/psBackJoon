#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int n, s, t = 1;
int ans = INF;
vector<int> v(100001);
vector<int> sum(100001);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    sum[i] = sum[i - 1] + v[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = t; j <= n; ++j) {
      if (sum[j] - sum[i - 1] >= s) {
        ans = min(ans, j - i + 1);
        t = j;
        break;
      }
    }
  }

  cout << (ans == INF ? 0 : ans);

  return 0;
}
