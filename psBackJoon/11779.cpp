#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

vector<vector<pair<int, int>>> v(1002);
vector<pair<int, int>> c(1002, pair<int, int>(INF, 0)); // {distance, before}
priority_queue<pair<int, int>> pq;
vector<int> path;

int n, m, s, e;
int t1, t2, t3;
int ans;

void dij(int x)
{
	c[x] = {0, 0};

	pq.push({ 0, x });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > c[cur].first) continue;
		for (auto vci : v[cur])
		{
			int next = vci.first;
			int nCost = vci.second;

			if (c[next].first > cost + nCost)
			{
				c[next] = { cost + nCost, cur };
				pq.push({ -c[next].first, next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({ t2, t3 });
	}

	cin >> s >> e;

	dij(s);

	cout << c[e].first << '\n';

	int idx = e;
	path.push_back(e);
	while (true)
	{
		if (idx == s) break;
		path.push_back(c[idx].second);
		idx = c[idx].second;
	}

	cout << path.size() << '\n';
	for (int i = path.size() - 1; i >= 0; --i) cout << path[i] << ' ';	

	return 0;
}