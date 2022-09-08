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

int n, m, t;
int x, y, ans;
vector<vector<int>> v;
vector<bool> ck;

bool dfs(int s, int e){
  ck[s] = true;

  for(auto vsi : v[s]) {
    if (vsi == e) continue;
    if (ck[vsi]) return false;
    if (!dfs(vsi, s)) return false;
  }

  return true;
}

void p(int num){
  switch (num) {
    case 1 :
      cout << "There is one tree.\n";
      break;
    case 0 :
      cout << "No trees.\n";
      break;
    default:
      cout << "A forest of " << num << " trees.\n";
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> n >> m;
    ++t;
    if (n == 0 && m == 0) break;

    v.assign(n + 1, vector<int>());
    ck.assign(n + 1, false);
    ans = 0;

    for (int i = 0; i < m; ++i){
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
      if (!ck[i])
        if (dfs(i, 0)) ++ans;
    }

    cout << "Case " << t << ": ";
    p(ans);
  }

  return 0;
}
