#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

vector<vector<pair<int, int>>> v;
vector<int> ans;

int T;
int n, m, t, s, g, h;
int a, b, d;
int ghDist;
int temp;

vector<int> st;
vector<int> gt;
vector<int> ht;

void dij(int start, vector<int>& vec)
{
  priority_queue<pair<int, int>> pq;
  vec[start] = 0;
  pq.push({ 0, start });

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    for (auto vcuri : v[cur])
    {
      int next = vcuri.first;
      int nCost = vcuri.second;

      if (vec[next] > cost + nCost)
      {
        vec[next] = cost + nCost;
        pq.push({ -vec[next], next });
      }
    }
  }
}

void solve()
{
  v.assign(2001, vector<pair<int, int>>());
  ans.clear();
  st.assign(2001, INF);
  gt.assign(2001, INF);
  ht.assign(2001, INF);

  cin >> n >> m >> t >> s >> g >> h;

  for (int i = 0; i < m; ++i)
  {
    cin >> a >> b >> d;
    v[a].push_back({ b, d });
    v[b].push_back({ a, d });

    if ((a == g && b == h) || (a == h && b == g)) ghDist = d;
  }

  // 1번루트 s-g-h-t
  // 2번루트 s-h-g-t
  dij(s, st);
  dij(g, gt);
  dij(h, ht);

  for (int i = 0; i < t; ++i)
  {
    cin >> temp;
    ans.push_back(temp);
  }

  sort(ans.begin(), ans.end());

  for (auto ansi : ans)
    if (st[g] + ghDist + ht[ansi] == st[ansi] || st[h] + ghDist + gt[ansi] == st[ansi]) // 1번루트 || 2번루트
      cout << ansi << ' ';

  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  for (int i = 0; i < T; ++i)
  {
    solve();
  }

  return 0;
}