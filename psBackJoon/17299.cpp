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

vector<int> v(1'000'001);
vector<int> cnt(1'000'001);
vector<int> ans(1'000'001);
stack<int> st;

int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    cnt[v[i]]++;
  };

  for (int i = n; i >= 0; --i) {
    while(!st.empty()) {
      if (cnt[v[i]] >= cnt[v[st.top()]]) st.pop();
      else break;
    }

    ans[i] = -1;
    if (!st.empty()) ans[i] = v[st.top()];
    st.push(i);
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';

  return 0;
}