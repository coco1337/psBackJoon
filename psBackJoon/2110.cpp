#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long int

using namespace std;

int n, c;
vector<int> v(200'001);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.begin() + n);

  ll l = 0, r = v[n - 1];

  ll ans = 0;

  while (r >= l)
  {
    ll mid = (r + l) / 2;
    int count = 1;
    int e = 0;
    for (int i = 1; i < n; ++i)
    {
      if (v[i] - v[e] >= mid)
      {
        e = i;
        ++count;
      }
    }

    if (count >= c)
    {
      l = mid + 1;
      if (ans < mid)
        ans = mid;
    }
    else
    {
      r = mid - 1;
    }
  }

  cout << ans;

  return 0;
}
