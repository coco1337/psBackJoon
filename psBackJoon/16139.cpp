#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
char c;

int q, l, r;
int cnt;

vector<vector<int>> v(26, vector<int>(200'002));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		++v[s[i] - 'a'][i + 1];
		for (int j = 0; j < 26; ++j)
		{
			v[j][i + 1] += v[j][i];
		}
	}

	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		cin >> c >> l >> r;
		cout << v[c - 'a'][r + 1] - v[c - 'a'][l] << '\n';
	}
}