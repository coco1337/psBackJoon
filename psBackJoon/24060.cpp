#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
int n, k;
int cnt;
vector<int> v(500'001);
vector<int> tmp(500'001);

void merge(int p, int q, int r)
{
  int i = p, j = q + 1, t = 1;
  while (i <= q && j <= r)
  {
    if (v[i] <= v[j]) tmp[t++] = v[i++];
    else tmp[t++] = v[j++];
  }
  while (i <= q) tmp[t++] = v[i++];
  while (j <= r) tmp[t++] = v[j++];
  i = p; t = 1;
  while (i <= r)
  {
    v[i] = tmp[t];
    cnt++;
    if (cnt == k) cout << tmp[t];
    t++; i++;
  }
}

void merge_sort(int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }

  merge_sort(0, n - 1);

  if (cnt < k) cout << -1;

  return 0;
}