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

string s1, s2;
vector<vector<int>> dp(1001, vector<int>(1001));

void print(int i, int j){
  if (dp[i][j] == 0) return;
  if (s1[i - 1] == s2[j - 1]) {
    print(i - 1, j - 1);
    cout << s1[i - 1];
  } else {
    dp[i - 1][j] > dp[i][j - 1] ? print(i - 1, j) : print(i, j - 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s1 >> s2;

  for (int i = 0; i < s1.size(); ++i) {
    for (int j = 0; j < s2.size(); ++j) {
      dp[i + 1][j + 1] = s1[i] == s2[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  cout << dp[s1.size()][s2.size()] << '\n';
  print(s1.size(), s2.size());

  return 0;
}
