#include <iostream>
#include <vector>

using namespace std;

int n;
int root;
vector<int> t(10'001);

void po(int s, int e)
{
	if (s >= e) return;
	if (s == e - 1)
	{
		cout << t[s] << '\n';
		return;
	}

	int idx = s + 1;
	while (idx < e)
	{
		if (t[s] < t[idx]) break;
		++idx;
	}

	po(s + 1, idx);
	po(idx, e);
	cout << t[s] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int i = 0;
	while (cin >> n)
	{
		// if (n == EOF) break;
		t[i++] = n;
	}

	po(0, i);
	return 0;
}