#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
int n, m;
int a, b;
int cnt;
vector<int> v(500'001);
vector<int> s(500'001);

int FindParent(int t){
  if (t == v[t]) return t;
  return v[t] = FindParent(v[t]);
}

bool MakeUnion(int n1, int n2){
  n1 = FindParent(n1);
  n2 = FindParent(n2);

  ++cnt;
  if (n1 < n2){
    v[n2] = n1;
    s[n1] += s[n2];
  } else if (n1 > n2) {
    v[n1] = n2;
    s[n2] += s[n1];
  } else {
    return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    v[i] = i;
    s[i] = 1;
  }

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    if (!MakeUnion(a, b)) {
      cout << cnt;
      return 0;
    }
  }

  cout << 0;
  return 0;
}