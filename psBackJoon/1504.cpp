#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

vector<vector<pair<int, int>>> g(801, vector<pair<int, int>>());

int n, e, a, b, c, v1, v2;
int r1, r2;

vector<int> m(801, INF);

void dij(int s)
{
	priority_queue<pair<int, int>> pq;

	m[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < g[cur].size(); ++i)
		{
			int next = g[cur][i].first;
			int iCost = g[cur][i].second;

			if (m[next] > cost + iCost)
			{
				m[next] = cost + iCost;
				pq.push({ -m[next], next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> e;

	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> c;

		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}

	cin >> v1 >> v2;

	// min(1->A->B->N, 1->B->A->N)
	dij(1);
	if (m[n] == INF)
	{
		cout << -1 << '\n';
		return 0;
	}

	int sa, sb, ab, an, bn;
	sa = m[v1];
	sb = m[v2];

	m.assign(801, INF);
	dij(v1);
	ab = m[v2];
	an = m[n];

	m.assign(801, INF);
	dij(v2);
	bn = m[n];
	
	r1 = sa + ab + bn;
	r2 = sb + ab + an;

	if (r1 >= INF && r2 >= INF)
	{
		cout << -1 << '\n';
		return 0;
	}

	cout << min(r1, r2) << '\n';

	return 0;
}