#include <iostream>
#include <vector>

using namespace std;
#define ll long long
vector<bool> v(1e6+1, true);
int n;

bool solve(){
  for (int i = 2; i*i <= 1e6; ++i) {
    if (v[i] && v[n - i]){
      cout << n << " = " << i << " + " << n-i << '\n';
      return true;
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (ll i = 2; i <= 1e6; ++i) {
    if (v[i]) {
      for (ll j = i*i; j <= 1e6; j += i)
        v[j] = false;
    }
  }

  while(cin >> n) {
    if (n == 0) return 0;

    if (!solve())
      cout << "Goldbach's conjecture is wrong.\n";
  }

  return 0;
}