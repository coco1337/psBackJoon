#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int x, y, w, h, p;
int vx, vy;
int rad;
int cnt;

bool Check(int a, int b)
{
	// 1. 사각형 범위 내에 있을 때
	if (a >= x && b >= y && a <= x + w && b <= y + h) return true;
	// 2. 아닌 경우 distance
	auto t = pow(y + rad - b, 2);
	auto s = pow(rad, 2);
	if (pow(x - a, 2) + t <= s) return true;
	if (pow(x + w - a, 2) + t <= s) return true;
	// 3. 둘다 아닌경우 false
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> w >> h >> x >> y >> p;
	rad = h / 2;

	for (int i = 0; i < p; ++i)
	{
		cin >> vx >> vy;
		cnt = Check(vx, vy) ? cnt + 1 : cnt;
	}

	cout << cnt;
	return 0;
}