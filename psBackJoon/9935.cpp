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

vector<char> v;
string s;
string bomb;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  cin >> bomb;

  for (int i = 0; i < s.size(); ++i) {
    v.push_back(s[i]);

    if (v.size() >= bomb.size()) {
      bool b = true;
      for (int j = 0; j < bomb.size(); ++j) {
        if (v[v.size() - bomb.size() + j] != bomb[j]) {
          b = false;
          break;
        }
      }

      if (b){
        for (int j = 0; j < bomb.size(); ++j) {
          v.pop_back();
        }
      }
    }
  }

  if (v.size() == 0) cout << "FRULA";
  else for (auto vi : v) cout << vi;

  return 0;
}