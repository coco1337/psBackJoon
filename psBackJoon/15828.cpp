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

#define ll long long

using namespace std;

int n;
int tmp;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  while (true) {
    cin >> tmp;

    if (tmp == -1) break;

    if (tmp == 0) q.pop();
    else {
      if (q.size() < n)
        q.push(tmp);
    }
  }

  if (q.empty()) {
    cout << "empty";
  } else {
    while(!q.empty()) {
      cout << q.front() << ' ';
      q.pop();
    }
  }

  return 0;
}