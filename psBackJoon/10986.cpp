#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

ll n, m, sum, ans;
ll t;

vector<ll> v(10e3 + 2);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		sum += t;
		++v[sum % m];
	}

	ans += v[0];

	for (int i = 0; i < m; ++i)
	{
		ans += v[i] * (v[i] - 1) / 2;
	}

	cout << ans << '\n';

	return 0;
}