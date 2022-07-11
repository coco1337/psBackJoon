#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a, b;
vector<pair<int, int>> v(6);

int maxW, maxH, subW, subH;
int wIdx, hIdx;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < 6; ++i)
	{
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}

	for (int i = 0; i < 6; ++i)
	{
		if (v[i].first == 1 || v[i].first == 2)
		{
			if (maxW < v[i].second)
			{
				maxW = v[i].second;
				wIdx = i;
			}
		}
		else
		{
			if (maxH < v[i].second)
			{
				maxH = v[i].second;
				hIdx = i;
			}
		}
	}

	subH = maxH - min(v[wIdx == 0 ? 5 : wIdx - 1].second, v[wIdx == 5 ? 0 : wIdx + 1].second);
	subW = maxW - min(v[hIdx == 0 ? 5 : hIdx - 1].second, v[hIdx == 5 ? 0 : hIdx + 1].second);

	cout << ((maxW * maxH) - (subW * subH)) * n << endl;

	return 0;
}