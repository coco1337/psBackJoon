#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int n, w;
int t1, t2;
vector<vector<int>> dp(1002, vector<int>(1002, INF));
vector<pair<int, int>> p1(1002, pair<int, int>());
vector<pair<int, int>> p2(1002, pair<int, int>());

int dist(int a, int b)
{
	if (a == w || b == w) return 0;
	if (dp[a][b] != INF) return dp[a][b];

	int dest = max(a, b) + 1;

	int dA = abs(p1[dest].first - p1[a].first) + abs(p1[dest].second - p1[a].second);
	int dB = abs(p2[dest].first - p2[b].first) + abs(p2[dest].second - p2[b].second);
	dp[a][b] = min(dist(dest, b) + dA, dist(a, dest) + dB);

	return dp[a][b];
}

void route(int a, int b)
{
	if (a == w || b == w) return;

	int dest = max(a, b) + 1;

	int dA = abs(p1[dest].first - p1[a].first) + abs(p1[dest].second - p1[a].second);
	int dB = abs(p2[dest].first - p2[b].first) + abs(p2[dest].second - p2[b].second);

	if (dp[dest][b] + dA < dp[a][dest] + dB)
	{
		cout << 1 << '\n';
		route(dest, b);
	}
	else
	{
		cout << 2 << '\n';
		route(a, dest);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> w;

	p1[0] = { 1, 1 };
	p2[0] = { n, n };

	for (int i = 1; i <= w; ++i)
	{
		cin >> t1 >> t2;
		p1[i] = {t1, t2};
		p2[i] = {t1, t2};
	}

	cout << dist(0, 0) << '\n';
	route(0, 0);

	return 0;
}