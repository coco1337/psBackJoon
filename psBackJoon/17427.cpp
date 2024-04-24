#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<int> v(1e6 + 1, 0);
int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    for (int j = 1; j * i <= n; ++j) {
      v[i] = v[i] + 1;
    }
  }

  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum = sum + v[i] * i;
  }

  cout << sum;

  return 0;
}