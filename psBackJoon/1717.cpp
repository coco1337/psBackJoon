#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;
int n, m;
int a,b,c;
vector<int> v(1'000'001);

int FindParent(int p) {
  if (v[p] == p) return p;
  else return v[p] = FindParent(v[p]);
}

void MakeUnion(int x, int y){
  int tx = FindParent(x);
  int ty = FindParent(y);

  if (tx > ty) v[tx] = ty;
  else if (tx < ty) v[ty] = tx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;

  for (int i = 0; i <= n; ++i) v[i] = i;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    if (a == 0) {
      MakeUnion(b, c);
    } else {
      if (FindParent(b) == FindParent(c)) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}
