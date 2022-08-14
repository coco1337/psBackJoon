#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int n, l, r, ans, t;
vector<bool> v(4e6 + 1, true);
vector<int> sum(4e6 + 1);

void eratos(int s)
{
  if (n <= 1) return;

  for (int i = 2; i * i <= s; ++i)
  {
    if (v[i])
    {
      for (int j = i * i; j <= s; j += i)
      {
        v[j] = false;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  eratos(n);

  v[0] = v[1] = false;

  for (int i = 1, j = 0; i <= n; ++i)
  {
    if (v[i])
    {
      sum[j + 1] = sum[j] + i;
      ++j;
    }
  }

  l = r = 1;
  while (true)
  {
    if (l > r || sum[r] == 0) break;

    t = sum[r] - sum[l - 1];
    if (t < n) ++r;
    else if (t == n)
    {
      ++ans;
      ++l;
    }
    else
    {
      ++l;
    }
  }

  cout << ans;
  return 0;
}
