#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(9);
int sum = 0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 9; ++i) {
    cin >> v[i];
    sum += v[i];
  }

  sort(v.begin(), v.end());

  int i, j;
  for (i = 0; i < 8; ++i) {
    for (j = i+1; j < 9; ++j) {
      if (sum - v[i] - v[j] == 100) {
        for (int k = 0; k < 9; ++k) {
          if (k == i || k == j) continue;
          cout << v[k] << '\n';
        }
        return 0;
      }
    }
  }

  return 0;
}