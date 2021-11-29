#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

// https://www.acmicpc.net/problem/2178

int n, m;
string s;

vector<vector<bool>> v(101, vector<bool>(101));
vector<vector<bool>> check(101, vector<bool>(101));
vector<vector<int>> cnt(101, vector<int>(101));
queue<pair<int, int>> q;
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, -1, 0, 1 };

void Bfs(int x, int y) {
	cnt[0][0] = 1;
	check[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		auto coord = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int a = coord.first + dx[i];
			int b = coord.second + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m) {
				if (!check[a][b] && v[a][b]) {
					q.push(make_pair(a, b));
					cnt[a][b] = cnt[coord.first][coord.second] + 1;
					check[a][b] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j) {
			v[i][j] = s[j] == '1';
		}
	}

	Bfs(0, 0);
	cout << cnt[n - 1][m - 1];

	return 0;
}