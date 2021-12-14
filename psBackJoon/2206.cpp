#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 999'999'999

using namespace std;

vector<vector<bool>> v(1001, vector<bool>(1001));
vector<vector<int>> chk(1001, vector<int>(1001));
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };
queue<pair<int, int>> changedq;
queue<pair<int, int>> q;

// 2206 -> 14442 -> 1175

int n, m, ans = MAX;
string s;

bool Check(int x, int y)
{
  return x >= 0 && y >= 0 && x < n&& y < m && !v[x][y];
}

void Bfs()
{
  q.push({ 0, 0 });
  vector<vector<bool>> visited(n, vector<bool>(m));

  while (!q.empty())
  {
    const auto qi = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int a = qi.first + dx[i];
      int b = qi.second + dy[i];

      if (Check(a, b) && !visited[a][b])
      {
        q.push({ a, b });
        chk[a][b] = chk[qi.first][qi.second] + 1;
        visited[a][b] = true;
      }
    }
  }
  if (visited[n - 1][m - 1])
    ans = min(ans, chk[n - 1][m - 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
  {
    cin >> s;
    for (int j = 0; j < s.size(); ++j)
    {
      v[i][j] = s[j] == '1';
      if (v[i][j]) changedq.push({ i, j });
    }
  }

  Bfs();

  while (!changedq.empty())
  {
    const auto qi = changedq.front();
    changedq.pop();
    int t = 0;
    for (int i = 0; i < 4; ++i)
    {
      int a = qi.first + dx[i];
      int b = qi.second + dy[i];

      if (Check(a, b)) ++t;   // 들어오는길 나가는길 있어야 의미가 있기때문에 필터
    }

    if (t > 1)
    {
      v[qi.first][qi.second] = false;
      Bfs();
      v[qi.first][qi.second] = true;
    }
  }

  if (ans == MAX) cout << -1;
  else cout << ans + 1;

  return 0;
}