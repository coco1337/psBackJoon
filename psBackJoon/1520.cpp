#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long int

using namespace std;

int n, m;

vector<vector<int>> v(501, vector<int>(501));
vector<vector<int>> dp(501, vector<int>(501, -1));

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int solve(int p, int q) {
  if (p == n - 1 && q == m - 1) return 1;
  if (dp[p][q] != -1) return dp[p][q];

  dp[p][q] = 0;
  for (int i = 0 ; i < 4; ++i) {
    int nx = p + dx[i];
    int ny = q + dy[i];

    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
      if (v[nx][ny] < v[p][q])
        dp[p][q] = dp[p][q] + solve(nx ,ny);
    }
  }

  return dp[p][q];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0 ; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
    }
  }

  cout << solve(0, 0);

  return 0;
}
