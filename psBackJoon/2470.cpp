#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x7f7f7f7f

using namespace std;

vector<int> v(1e6 + 1);
int n, lIdx, rIdx;
int l, r, sum = INF;
int t, s;

// -99 -2 -1 4 98 99

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.begin() + n);

  l = lIdx = 0;
  r = rIdx = n - 1;

  while (true)
  {
    if (r - l < 1) break;

    s = v[l] + v[r];
    t = abs(s);

    if (sum > t)
    {
      sum = t;
      lIdx = l;
      rIdx = r;
    }

    if (s < 0) ++l;
    else if (s > 0) --r;
    else break;
  }

  cout << v[lIdx] << ' ' << v[rIdx];

  return 0;
}
