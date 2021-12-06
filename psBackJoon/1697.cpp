#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 999'999'999
using namespace std;

int n, m, cnt;
vector<bool> v(100'001);
vector<int> c(100'001);
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	if (m <= n) {
		cout << n - m;
		return 0;
	}

	q.push(n);

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == m) break;

		if (t > 0 && !v[t - 1]) {
			q.push(t - 1);
			v[t - 1] = true;
			c[t - 1] = c[t] + 1;
		}

		if (t < 100'000 && !v[t + 1]) {
			q.push(t + 1);
			v[t + 1] = true;
			c[t + 1] = c[t] + 1;
		}

		if (t * 2 <= 100'000 && !v[t * 2]) {
			q.push(t * 2);
			v[t * 2] = true;
			c[t * 2] = c[t] + 1;
		}
	}

	cout << c[m];

	return 0;
}