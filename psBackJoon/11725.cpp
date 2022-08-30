#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v(100'001);
vector<int> p(100'001);
queue<int> q;
int n, p1, p2, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}

	q.push(1);
	while (!q.empty())
	{
		t = q.front();
		q.pop();

		for (auto vti : v[t])
		{
			if (p[vti] == 0 && vti != 1)
			{
				p[vti] = t;
				q.push(vti);
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		cout << p[i] << '\n';
	}

	return 0;
}