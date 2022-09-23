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

using namespace std;

vector<int> x = {0, 1, 0, 1};
vector<int> y = {0, 0, 1, 1};
vector<pair<int, int>> v;
int height;
int width;

int CheckBoard(vector<string>& b) {
  int count = 0;
  for (int i = 0; i < height - 1; ++i) {
    for (int j = 0; j < width - 1; ++j) {
      auto target = b[i][j];
      if (target == '^') continue;
      bool ck = true;

      for (int k = 0; k < 4; ++k) {
        if (target != b[i + y[k]][j + x[k]])  {
          ck = false;
          break;
        }
      }

      if (ck) {
        v.push_back({i, j});
        ++count;
      }
    }
  }

  return count;
}

int DeleteBlocks(int p, int q, vector<string>& b) {
  int cnt = 0;
  for (int i = 0; i < 4; ++i) {
    if (b[p + y[i]][q + x[i]] != '^'){
      b[p+y[i]][q+x[i]] = '^';
      ++cnt;
    }
  }

  return cnt;
}

void RefreshBoard(vector<string>& board){
  for (int i = 0; i < width; ++i) {
    for (int j = height - 1; j > 0 ; --j) {
      if (board[j][i] == '^') {
        for (int k = j - 1; k >= 0; --k) {
          if (board[k][i] != '^') {
            board[j][i] = board[k][i];
            board[k][i] = '^';
            break;
          }
        }
      }
    }
  }
}

int solution(int m, int n, vector<string> board) {
  int answer = 0;
  height = m;
  width = n;

  while(CheckBoard(board) > 0) {
    for (auto vi : v) {
      answer += DeleteBlocks(vi.first, vi.second, board);
    }
    RefreshBoard(board);
    v.clear();
  }

  return answer;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> a = {"AAAAAA", "BBAATB", "BBAATB", "JJJTAA", "JJJTAA"};
  auto v = solution(5, 6, a);
  cout << v;

  return 0;
}