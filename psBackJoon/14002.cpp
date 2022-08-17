#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
vector<int> v(1001);
vector<int> dp(1001);
vector<vector<int>> a(1001);
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> v[i];

	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		a[i].push_back(v[i]);

		for (int j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					a[i].clear();
					a[i] = a[j];
					a[i].push_back(v[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}

		if (ans.size() < a[i].size()) ans = a[i];
	}

	cout << ans.size() << '\n';
	for (auto ansi : ans) cout << ansi << ' ';

	return 0;
}