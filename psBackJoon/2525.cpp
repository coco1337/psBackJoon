#include <iostream>

using namespace std;

int a, b, c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b >> c;

	a += c / 60;
	int t = c % 60;
	if (t > 0 && t + b >= 60)
	{
		++a;
	}

	b += c % 60;

	cout << a % 24 << " " << b % 60 << endl;
}