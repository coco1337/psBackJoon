#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int n, c, ans;
vector<ll> v(31);
vector<ll> b1;
vector<ll> b2;

void dfs(int s, int e, vector<ll>& b, ll sum)
{
  if (s > e)
  {
    b.push_back(sum);
    return;
  }
  else
  {
    dfs(s + 1, e, b, sum);
    dfs(s + 1, e, b, sum + v[s]);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;
  for (int i = 0; i < n; ++i) cin >> v[i];

  dfs(0, n / 2 - 1, b1, 0);
  dfs(n / 2, n - 1, b2, 0);

  sort(b2.begin(), b2.end());

  for (auto b1i : b1)
  {
    ll x = c - b1i;
    ans += upper_bound(b2.begin(), b2.end(), x) - b2.begin();
  }

  cout << ans;
  return 0;
}

