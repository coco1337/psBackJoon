#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long int

using namespace std;

int n, m, ans, sum;

vector<int> v(102);
vector<int> c(102);

vector<vector<int>> dp(102, vector<int>(10'002));

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    sum += c[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j){
      if (j - c[i] >= 0)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + v[i]);

      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }

  for (int i = 0 ; i <= sum; ++i){
    if (dp[n][i] >= m){
      cout << i;
      break;
    }
  }

  return 0;
}
