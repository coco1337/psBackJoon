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

int n, t;
vector<int> inorder(100'001);
vector<int> postorder(100'001);
vector<int> idx(100'001);

void preorder(int is, int ie, int ps, int pe) {
  if (is > ie || ps > pe) return;

  int root = idx[postorder[pe]];
  int lSize = root - is;
  int rSize = ie - root;

  cout << inorder[root] << ' ';

  preorder(is, root - 1, ps, ps + lSize - 1);
  preorder(root + 1, ie, ps + lSize, pe - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> inorder[i];
    idx[inorder[i]] = i;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> postorder[i];
  }

  preorder(1, n, 1, n);

  return 0;
}
