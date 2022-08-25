#include <iostream>
#include <queue>
#include <stack>

using namespace std;

vector<bool> v(10001);
vector<pair<int, char>> dp(10001, {-1, '\0'});

int t, a, b;
int p;

vector<int> dslr(4);

int D(int x)
{
	return (x * 2) % 10000;
}

int S(int x)
{
	if (x == 0) return 9999;
	else return x - 1;
}

int L(int x)
{
	int e4, e3, e2, e1;
	e4 = x / 1000;
	e3 = (x % 1000) / 100;
	e2 = (x % 100) / 10;
	e1 = x % 10;

	return ((e3 * 10 + e2) * 10 + e1) * 10 + e4;
}

int R(int x)
{
	int e4, e3, e2, e1;
	e4 = x / 1000;
	e3 = (x % 1000) / 100;
	e2 = (x % 100) / 10;
	e1 = x % 10;

	return ((e1 * 10 + e4) * 10 + e3) * 10 + e2;
}

void Init()
{
	v.assign(10001, false);
	dp.assign(10001, { -1, '\0' });
	dslr.assign(4, 0);
}

void solve()
{
	Init();
	queue<int> q;
	stack<char> path;

	cin >> a >> b;

	q.push(a);
	v[a] = true;

	while (!q.empty())
	{
		p = q.front();
		q.pop();

		if (p == b) break;

		int d, s, l, r;
		d = D(p);
		s = S(p);
		l = L(p);
		r = R(p);

		if (!v[d])
		{
			v[d] = true;
			q.push(d);
			dp[d] = {p, 'D'};
		}

		if (!v[s])
		{
			v[s] = true;
			q.push(s);
			dp[s] = { p, 'S' };
		}

		if (!v[l])
		{
			v[l] = true;
			q.push(l);
			dp[l] = { p, 'L' };
		}

		if (!v[r])
		{
			v[r] = true;
			q.push(r);
			dp[r] = { p, 'R' };
		}
	}

	int next = b;

	while (true)
	{
		if (next == a) break;
		path.push(dp[next].second);
		next = dp[next].first;
	}

	while (!path.empty())
	{
		cout << path.top();
		path.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		solve();
		cout << '\n';
	}

	return 0;
}