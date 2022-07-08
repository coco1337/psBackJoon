#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int t;
set<int> a;
int c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		a.insert(t);
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		c = a.find(t) != a.end() ? c + 1: c;
	}

	cout << (n + m) - (2 * c) << endl;

	return 0;
}