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

vector<vector<pair<int, int>>> a(100'001);
vector<bool> ck(100'001);
queue<int> q;

int v, p, x, y;
int maxDist, maxNode;

void dfs(int n, int d)
{
  if (ck[n]) return;

  if (maxDist < d)
  {
    maxDist = d;
    maxNode = n;
  }

  ck[n] = true;

  for (auto ani : a[n])
  {
    dfs(ani.first, ani.second + d);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v;

  for (int i = 0; i < v; ++i)
  {
    cin >> p;
    while (true)
    {
      cin >> x;
      if (x == -1) break;
      cin >> y;

      a[p].push_back({ x, y });
      a[x].push_back({ p, y });
    }
  }

  dfs(1, 0);
  ck.assign(100'001, false);
  maxDist = 0;
  dfs(maxNode, 0);
  cout << maxDist;

  return 0;
}
