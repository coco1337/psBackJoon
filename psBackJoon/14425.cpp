#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m;
string t;
set<string> s;
int ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
  {
    cin >> t;
    s.insert(t);
  }

  for (int i = 0; i < m; ++i)
  {
    cin >> t;
    if (s.find(t) != s.end())
    {
      ++ans;
    }
  }

  cout << ans;

  return 0;
}