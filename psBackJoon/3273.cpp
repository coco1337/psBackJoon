#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int n, x, t, idx;
int cnt;
vector<int> v(1e6 + 1);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  sort(v.begin(), v.begin() + n);

  cin >> x;
  idx = n - 1;

  for (int i = 0; i < idx - 1; ++i)
  {
    for (int j = idx; j >= i; --j)
    {
      t = v[i] + v[j];
      if (t < x) break;
      else if (t == x)
      {
        ++cnt;
        idx = j;
        break;
      }
    }
  }

  cout << cnt;

  return 0;
}
