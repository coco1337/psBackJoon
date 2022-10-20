#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

#define ll long long

using namespace std;

int n, h;
ll ans;
vector<int> v(500'002);
stack<pair<int,int>> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> h;
    int sameHeight = 1;

    while (!st.empty() && st.top().first < h) {
      ans += st.top().second;
      st.pop();
    }

    if (!st.empty()) {
      if (st.top().first == h) {
        ans += st.top().second;
        sameHeight = st.top().second + 1;
        if (st.size() > 1) ++ans;
        st.pop();
      } else ++ans;
    }

    st.push({h, sameHeight});
  }

  cout << ans;

  return 0;
}