#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int king, queen, rook, bishop, knight, pawn;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> king >> queen >> rook >> bishop >> knight >> pawn;
  cout << 1 - king << ' ';
  cout << 1 - queen << ' ';
  cout << 2 - rook << ' ';
  cout << 2 - bishop << ' ';
  cout << 2 - knight << ' ';
  cout << 8 - pawn;

  return 0;
}
