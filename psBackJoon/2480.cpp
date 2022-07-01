#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(3);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());

	if (v[0] == v[1] && v[1] == v[2])
	{
		cout << 10000 + v[0] * 1000 << endl;
	}
	else if (v[0] == v[1] || v[1] == v[2])
	{
		cout << 1000 + v[1] * 100 << endl;
	}
	else
	{
		cout << v[2] * 100 << endl;
	}

	return 0;
}