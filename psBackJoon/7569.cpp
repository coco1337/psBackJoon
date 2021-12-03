#include <iostream>
#include <vector>
#include <math.h>
#include <tuple>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/7569

int n, m, h, cnt;
bool o;

vector<vector<vector<int>>> v(101, vector<vector<int>>(101, vector<int>(101)));
queue<tuple<int, int, int>> q;
vector<tuple<int, int, int>> d = { {-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> m >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < h; ++k) {
				cin >> v[i][j][k];
				if (v[i][j][k] == 1) q.push({ i,j,k });
				else if (v[i][j][k] == 0) o = true;
			}
		}
	}

	if (!o) {
		cout << '0';
		return 0;
	}

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		for (auto di : d) {
			int x = get<0>(p) + get<0>(di);
			int y = get<1>(p) + get<1>(di);
			int z = get<2>(p) + get<2>(di);
			if (x < 0 || y < 0 || z < 0) continue;
			if (x >= n || y >= m || z >= h) continue;
			if (v[x][y][z] >= 1 || v[x][y][z] < 0) continue;
			v[x][y][z] = v[get<0>(p)][get<1>(p)][get<2>(p)] + 1;
			q.push({ x,y,z });
			cnt = max(cnt, v[x][y][z]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < h; ++k) {
				if (v[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << cnt - 1;
	return 0;
}