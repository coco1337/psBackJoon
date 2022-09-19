#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> v(s.size());
    for (int i = 0; i < s.size(); ++i) {
        v[i] = s[i];
    }
    sort(v.begin(), v.end(), greater<char>());
    for (auto vi : v) {
        answer += vi;
    }
    return answer;
}

string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> str;

  auto answer = solution(str);

  return 0;
}