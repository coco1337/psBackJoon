#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

int n, a, b, c;
int ans, r;
vector<vector<pair<int, int>>> v(10001);
vector<bool> d(10001);

void dfs(int s, int dist)
{
	d[s] = true;

	if (dist > ans)
	{
		ans = dist;
		r = s;
	}

	for (auto vsi : v[s])
	{
		int next = vsi.first;
		int nDist = vsi.second + dist;

		if (!d[next])
		{
			d[next] = true;
			dfs(next, nDist);
			d[next] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b >> c;

		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	dfs(1, 0);
	ans = 0;
	d.assign(10001, false);
	dfs(r, 0);
	cout << ans;

	return 0;
}