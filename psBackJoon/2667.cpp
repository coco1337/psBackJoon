#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

//https://www.acmicpc.net/problem/2667

int n;
vector<vector<int>> v(26, vector<int>(26));
vector<vector<bool>> b(26, vector<bool>(26));
vector<int> ans(625);
int c;
string s;
vector<pair<int, int>> axis{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };	// 왼쪽 위 오른쪽 아래

void dfs(int x, int y) {
	if (v[x][y] == 1 && b[x][y] == false) {
		b[x][y] = true;
		ans[c]++;
		for (auto ai : axis) {
			if (x + ai.first >= 0 && x + ai.first < n && y + ai.second >= 0 && y + ai.second < n) {
				dfs(x + ai.first, y + ai.second);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < s.length(); ++j) {
			v[i][j] = s[j] - '0';
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == 1 && b[i][j] == false) {
				dfs(i, j);
				c++;
			}	
		}
	}
		
	cout << c << '\n';
	sort(ans.begin(), ans.begin() + c);

	for (int i = 0; i < c; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}