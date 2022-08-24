#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

vector<bool> v(100'001);
vector<int> b(100'001);
vector<int> path;
int n, k;
pair<int, int> t, p;

queue<pair<int, int>> q;

int bfs(int s, int f)
{
	v[s] = true;
	q.push({ s, 0 });

	while (!q.empty())
	{
		t = q.front();
		q.pop();

		if (t.first == k)
		{
			int idx = t.first;

			while (idx != n)
			{
				path.push_back(idx);
				idx = b[idx];
			}

			path.push_back(n);
			return t.second;
		}

		if (t.first + 1 < 100'001 && !v[t.first + 1])
		{
			q.push({ t.first + 1, t.second + 1 });
			v[t.first + 1] = true;
			b[t.first + 1] = t.first;
		}

		if (t.first - 1 >= 0 && !v[t.first - 1])
		{
			q.push({ t.first - 1, t.second + 1 });
			v[t.first - 1] = true;
			b[t.first - 1] = t.first;
		}

		if (t.first * 2 < 100'001 && !v[t.first * 2])
		{
			q.push({ t.first * 2, t.second + 1 });
			v[t.first * 2] = true;
			b[t.first * 2] = t.first;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	cout << bfs(n, k) << '\n';

	for (int i = path.size() - 1; i >= 0; --i)
	{
		cout << path[i] << ' ';
	}

	return 0;
}