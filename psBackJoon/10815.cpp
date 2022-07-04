#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int a, b, t;
set<int> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a;
  for (int i = 0; i < a; ++i)
  {
    cin >> t;
    s.insert(t);
  }

  cin >> b;
  for (int i = 0; i < b; ++i)
  {
    cin >> t;
    if (s.find(t) == s.end()) cout << "0 ";
    else cout << "1 ";
  }


  return 0;
}