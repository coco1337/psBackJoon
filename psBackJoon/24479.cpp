#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m, r;
vector<vector<int>> v(100'001, vector<int>());
vector<int> c(100'001);

int a, b;
int cnt;

void dfs(int start) {
    if (c[start] != 0) return;

    c[start] = ++cnt;
    for (auto vsi : v[start])
        dfs(vsi);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());

    dfs(r);

    for (int i = 1; i <= n; ++i) {
        cout << c[i] << "\n";
    }

    return 0;
}
