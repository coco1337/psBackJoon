#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long> dp(2001);

int x;

long long solution(int n)
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
	}

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> x;

	cout << solution(x);

	return 0;
}