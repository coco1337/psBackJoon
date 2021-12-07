#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/7562

vector<int> dx = { -2, -1, 1, 2, 2, 1, -1, -2 };
vector<int> dy = { 1,2,2,1,-1,-2,-2,-1 };

int n, m, sx, sy, ex, ey;

bool RouteCheck(int e1, int e2) {
	return e1 >= 0 && e2 >= 0 && e1 < m&& e2 < m;
}

void Solve() {
	vector<vector<int>> w(m, vector<int>(m));
	vector<vector<bool>> v(m, vector<bool>(m));
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	v[sx][sy] = true;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.first == ex && t.second == ey) {
			cout << w[ex][ey];
			return;
		}

		for (int i = 0; i < 8; ++i) {
			int a = t.first + dx[i];
			int b = t.second + dy[i];

			if (RouteCheck(a, b) && !v[a][b]) {
				q.push({ a, b });
				v[a][b] = true;
				w[a][b] = w[t.first][t.second] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m >> sx >> sy >> ex >> ey;
		Solve();
	}

	return 0;
}