#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int a, b;

vector<int> v(100'001);
vector<int> sum(100'001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}

	return 0;
}