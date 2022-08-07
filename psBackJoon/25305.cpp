#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

vector<int> v(1001);
int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.begin() + n, greater<int>());

  cout << v[k - 1];

  return 0;
}
