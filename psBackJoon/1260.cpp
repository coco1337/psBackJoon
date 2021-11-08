#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/1260

int n, m, v;
int x, y;

vector<vector<bool>> a(1001, vector<bool>(1001));
vector<bool> visited(1001);

void dfs(int c) {
	cout << c << ' ';
	visited[c] = true;
	for (int i = 1; i <= n; ++i) {
		if (visited[i] || !a[c][i]) continue;
		dfs(i);
	}
}

void bfs(int c) {
	queue<int> q;
	q.push(c);
	visited[c] = false;
	while (!q.empty()) {
		c = q.front();
		cout << c << ' ';
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (!visited[i] || !a[c][i]) continue;
			q.push(i);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		a[y][x] = true;
		a[x][y] = true;
	}

	dfs(v);
	cout << '\n';
	bfs(v);
}