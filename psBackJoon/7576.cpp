#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

// https://www.acmicpc.net/problem/7576

vector<vector<int>> v(1001, vector<int>(1001));
vector<vector<int>> days(1001, vector<int>(1001));
queue<pair<int, int>> q;
vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };
int cnt;
bool o;

int n, m, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1) q.push({ i, j });
			else if (v[i][j] == 0) o = true;
		}
	}

	if (!o) {
		cout << '0';
		return 0;
	}

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int a = p.first + dx[i];
			int b = p.second + dy[i];
			if (a < 0 || b < 0 || a >= n || b >= m) continue;
			if (v[a][b] >= 1 || v[a][b] < 0) continue;
			v[a][b] = v[p.first][p.second] + 1;
			q.push({ a, b });
			cnt = max(cnt, v[a][b]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << cnt - 1;

	return 0;
}