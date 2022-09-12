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
int a;
int path = 0;
bool ans = true;

vector<int> v(201);

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

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a;
      if (a == 1) {
        int tx = FindParent(i);
        int ty = FindParent(j);
        if (tx == ty) continue;
        else MakeUnion(tx, ty);
      }
    }
  }

  cin >> a;
  path = FindParent(a);
  for (int i = 1; i < m; ++i) {
    cin >> a;
    if (path != FindParent(a)) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "YES" : "NO");

  return 0;
}
