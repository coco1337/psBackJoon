#include <iostream>
#include <vector>

using namespace std;

vector<int> v(100'001);

int n, k;
int t;
int ans = -999999999;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> t;
		v[i] = v[i - 1] + t;
	}

	for (int i = 0; i <= n - k; ++i)
	{
		t = v[i + k] - v[i];
		ans = ans > t ? ans : t;
	}

	cout << ans;
	return 0;
}