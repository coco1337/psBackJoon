#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#include <stack>
#include <string>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int n;
char a, b, c, r;
vector<pair<char, char>> v(27, {'.', '.'});
void preorder(char x) {
  if (x == '.') return;

  cout << x;

  preorder(v[x - 'A'].first);
  preorder(v[x - 'A'].second);
}

void inorder(char x) {
  if (x == '.') return;

  inorder(v[x - 'A'].first);
  cout << x;
  inorder(v[x - 'A'].second);
}

void postorder(char x) {
  if (x == '.') return;

  postorder(v[x - 'A'].first);
  postorder(v[x - 'A'].second);
  cout << x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  cin >> a >> b >> c;
  v[a - 'A'] = {b, c};
  r = a;

  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b >> c;
    v[a - 'A'] = {b, c};
  }

  preorder(r);
  cout << '\n';
  inorder(r);
  cout << '\n';
  postorder(r);

  return 0;
}
