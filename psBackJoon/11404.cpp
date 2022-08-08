#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int a, b, c;

vector<vector<int>> v(101, vector<int>(101, INF));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		v[a][b] = min(v[a][b], c);
	}

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= n; ++k)
				v[j][k] = min(v[j][i] + v[i][k], v[j][k]);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << (i == j ? 0 : ((v[i][j] >= INF) ? 0 : v[i][j])) << " ";
		}

		cout << '\n';
	}
		
			

	return 0;
}