#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int n, m, t;
int a1, a2, b1, b2;
vector<vector<int>> v(1026, vector<int>(1026));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> t;
			v[i][j] = v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1] + t;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a1 >> b1 >> a2 >> b2;

		cout << v[a2][b2] - v[a1 - 1][b2] - v[a2][b1 - 1] + v[a1 - 1][b1 - 1] << '\n';
	}


	return 0;
}