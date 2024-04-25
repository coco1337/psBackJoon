#include <iostream>

using namespace std;

int e, s, m;
int sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> e >> s >> m;
  sum = 1;
  while (!(e == 1 && s == 1 && m == 1)){
    --e; --s; --m;
    if (e == 0) e = 15;
    if (s == 0) s = 28;
    if (m == 0) m = 19;
    ++sum;
  }

  cout << sum;

  return 0;
}