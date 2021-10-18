#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> a(31);
vector<vector<bool>> dp(31, vector<bool>(30 * 500 + 1));

// https://www.acmicpc.net/problem/2629

void solve(int i, int w) {
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;
	solve(i + 1, w + a[i]);	// ������������ a[i]������ �ֱ�
	solve(i + 1, abs(w - a[i]));	// ������ �ݴ������� a[i] ���� �ֱ�
	solve(i + 1, w);	// �ƹ��͵� ���� �ʱ�
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	solve(0, 0);

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> k;
		if (k > 15000) cout << "N ";
		else if (dp[n][k]) cout << "Y ";
		else cout << "N ";
	}

}