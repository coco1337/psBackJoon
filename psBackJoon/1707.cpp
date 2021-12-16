#include <iostream>
#include <vector>

using namespace std;

int k, v, e;
int u1, u2;
vector<int> visited;
vector<vector<int>> m;

void Dfs(int x, int color) {
	visited[x] = color;
	for (auto mxi : m[x]) {
		if (visited[mxi] == 0) {
			Dfs(mxi, 3 - color);
		}
	}
}

bool IsBipartite() {
	for (int i = 1; i <= v; ++i) {
		for (auto mij : m[i]) {
			if (visited[i] == visited[mij]) return false;
		}
	}

	return true;
}

void Solve() {
	visited.assign(v + 1, 0);
	m.assign(v + 1, vector<int>(0));

	for (int i = 0; i < e; ++i) {
		cin >> u1 >> u2;
		m[u1].push_back(u2);
		m[u2].push_back(u1);
	}

	for (int i = 1; i <= v; ++i)
		if (visited[i] == 0) 
			Dfs(i, 1);

	if (IsBipartite()) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> v >> e;
		Solve();
	}

	return 0;
}