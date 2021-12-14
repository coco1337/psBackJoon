#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };
vector<vector<bool>> g(1001, vector<bool>(1001));
vector<vector<vector<int>>> v(1001, vector<vector<int>>(1001, vector<int>(2)));

// 2206 -> 14442 -> 1175

int n, m;
string s;

bool Check(int x, int y)
{
  return x >= 0 && y >= 0 && x < n&& y < m;
}

int Bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push({{ 0,0 }, 1});
  v[0][0][1] = 1;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int b = q.front().second;
    q.pop();

    if (y == n - 1 && x == m - 1) {
      return v[y][x][b];
    }

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (Check(ny, nx)) {
        if (g[ny][nx] && b) {
          v[ny][nx][b - 1] = v[y][x][b] + 1;
          q.push({ {ny, nx}, b - 1 });
        }

        if (!g[ny][nx] && v[ny][nx][b] == 0) {
          v[ny][nx][b] = v[y][x][b] + 1;
          q.push({ {ny, nx}, b });
        }
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      g[i][j] = '1' == s[j];
    }
  }

  cout << Bfs() << '\n';

  return 0;
}