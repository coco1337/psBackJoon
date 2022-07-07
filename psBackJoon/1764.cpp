#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans;
string str;
set<string> s;
vector<string> v(500'001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> str;
		if (s.find(str) == s.end()) continue;
		v[ans] = str;
		ans++;
	}

	cout << ans << endl;
	sort(v.begin(), v.begin() + ans);
	for (int i = 0; i < ans; ++i)
	{
		cout << v[i] << endl;
	}

	return 0;
}