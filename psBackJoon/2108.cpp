#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v(500'001);
vector<int> tot(8001); // -4000 ~ 4000

int n, sum;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
    ++tot[v[i] + 4000];
    sum += v[i];
  }

  // »ê¼úÆò±Õ
  int avg = round(sum / (double)n);
  avg == 0 ? 0 : avg;
  cout << avg << endl;

  // Áß¾Ó°ª
  sort(v.begin(), v.begin() + n);
  cout << v[n / 2] << endl;

  // ÃÖºó°ª
  auto p = max_element(tot.begin(), tot.end());
  int pIdx = p - tot.begin() - 4000;
  auto q = max_element(p + 1, tot.end());
  int qIdx = q - tot.begin() - 4000;
  int ans = *p == *q ? qIdx : pIdx;
  ans = ans > 4000 ? ans - 1 : ans;
  cout << ans << endl;

  // ¹üÀ§
  cout << v[n - 1] - v[0] << endl;
  return 0;
}
