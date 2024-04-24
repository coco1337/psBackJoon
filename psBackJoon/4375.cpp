#include <iostream>

#define ll unsigned long long

using namespace std;

ll i = 1;
ll n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> n) {
    int sum = 1;
    while (i % n != 0) {
      i = (i % n) * 10 + 1;
      ++sum;
    }

    cout << sum << '\n';
    i = 1;
  }

  return 0;
}