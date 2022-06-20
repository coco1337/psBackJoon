#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 999999999
#define MAX 22222

using namespace std;

int v, e, k;
int x, y, z;
vector<int> d(20002);
vector<vector<pair<int, int>>> arr(20002);
priority_queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> v >> e >> k;

	for (int i = 0; i < e; ++i)
	{
		cin >> x >> y >> z;
		arr[x].push_back(make_pair(y, z));
	}

	for (int i = 1; i <= v; ++i)
		d[i] = INF;

	pq.push(make_pair(0, k));
	d[k] = 0;
	
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < arr[cur].size(); ++i)
		{
			int next = arr[cur][i].first;
			int nCost = arr[cur][i].second;

			if (d[next] > cost + nCost)
			{
				d[next] = cost + nCost;
				pq.push(make_pair(-d[next], next));
			}
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}

	return 0;
}