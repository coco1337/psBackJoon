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

using namespace std;

int n, ans;
vector<int> v(100'002);
stack<int> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  st.push(0);

  for (int i = 1; i <= n + 1; ++i){
    while(!st.empty() && v[st.top()] > v[i]) {
      int check = st.top();
      st.pop();
      ans = max(ans, v[check] * (i - st.top() - 1));
    }
    st.push(i);
  }

  cout << ans;

  return 0;
}