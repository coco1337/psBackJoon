#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

int v, e;
int a, b, c;
int ans;

vector<int> pa(10'001);
vector<pair<int, pair<int, int>>> g;

int Find(int x) {
  if (pa[x] == x) return x;
  return pa[x] = Find(pa[x]);
}

void Union(int x, int y){
  x = Find(x);
  y = Find(y);

  if (x != y) pa[y] = x;
}

bool IsSameParent(int x, int y){
  return Find(x) == Find(y);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v >> e;

  for (int i = 0; i < e; ++i) {
    cin >> a >> b >> c;
    g.push_back({c, {a, b}});
  }

  sort(g.begin(), g.end());

  for (int i = 0; i <= v; ++i) pa[i] = i;

  for (int i = 0 ; i < e; ++i) {
    if (!IsSameParent(g[i].second.first, g[i].second.second)){
      Union(g[i].second.first, g[i].second.second);
      ans += g[i].first;
    }
  }

  cout << ans;

  return 0;
}