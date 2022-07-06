#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> its(100'002);
unordered_map<string, int> sti;

int n, m;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> s;

		its[i] = s;
		sti.insert({ s, i });
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') cout << its[stoi(s)] << '\n';
		else cout << sti[s] << '\n';
	}

	return 0;
}