#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<int> dp(1e6 + 1);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		if (i % 3 == 0 && i % 2 == 0) dp[i] = min(min(dp[i / 3] + 1, dp[i / 2] + 1), dp[i - 1] + 1);
		else if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		else if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		else dp[i] = dp[i - 1] + 1;
	}

	cout << dp[n] - 1 << '\n';
	m = dp[n];

	while (n >= 1)
	{
		cout << n << " ";

		if (n == 1) break;

		--m;
		if (dp[n - 1] == m) --n;
		else if (n % 2 == 0 && dp[n / 2] == m) n /= 2;
		else if (n % 3 == 0 && dp[n / 3] == m) n /= 3;
	}

	return 0;
}