#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
int T, n, m;
int a, b;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> n >> m;
    for (int j = 0; j < m; ++j) {
      cin >> a >> b;
    }
    cout << n - 1 << '\n';
  }

  return 0;
}