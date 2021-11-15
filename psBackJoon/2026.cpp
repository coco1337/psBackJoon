#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/2606

int n, m, x, y;
vector<int> v;
vector<vector<bool>> a(101, vector<bool>(101));
vector<bool> visited(101);
queue<int> q;
int s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		a[x][y] = true;
		a[y][x] = true;
	}

	q.push(1);

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		visited[t] = true;
		for (int i = 1; i <= n; ++i) {
			if (a[t][i]) {
				a[t][i] = 0;
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (visited[i]) ++s;
	}

	cout << s - 1;
}