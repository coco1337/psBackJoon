#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int t, f, cnt, a, b;
string s1, s2;
unordered_map<string, int> m;
vector<int> p(200'001);
vector<int> s(200'001);

int FindParent(int n) {
  if (n == p[n]) return n;
  return p[n] = FindParent(p[n]);
}

void MakeUnion(int n1, int n2) {
  n1 = FindParent(n1);
  n2 = FindParent(n2);

  if (n1 < n2){
    p[n2] = n1;
    s[n1] += s[n2];
  } else if (n1 > n2) {
    p[n1] = n2;
    s[n2] += s[n1];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;

  for (int i = 0; i < t; ++i) {
    cin >> f;
    m.clear();
    cnt = 0;

    for (int j = 0; j < 200001; ++j) {
      p[j] = j;
      s[j] = 1;
    }

    for (int j = 0; j < f; ++j) {
      cin >> s1 >> s2;
      if(m.find(s1) == m.end()) {
        m[s1] = ++cnt;
        a = cnt;
      } else a = m[s1];

      if (m.find(s2) == m.end()){
        m[s2] = ++cnt;
        b = cnt;
      } else b = m[s2];

      MakeUnion(a, b);
      cout << s[FindParent(a)] << '\n';
    }
  }

  return 0;
}