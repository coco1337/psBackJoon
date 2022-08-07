#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int x, n, a, b;
int sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> x >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    sum += a * b;
  }

  cout << ((x == sum) ? "Yes" : "No");

  return 0;
}
