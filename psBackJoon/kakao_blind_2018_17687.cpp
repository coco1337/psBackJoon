// https://school.programmers.co.kr/learn/courses/30/lessons/17687

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
vector<char> arr = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// m으로 나눈 나머지가 p - 1이어야 함
string solution(int n, int t, int m, int p) {
  string answer = "";

  string a = "0";
  int i = 0;
  while (true) {
    if (a.size() >= t * m) break;
    string b = "";
    int j = i;
    while (j) {
      b = arr[j % n] + b;
      j = j / n;
    }

    a += b;
    ++i;
  }

  for (int i = 0; i < a.size(); ++i) {
    if (i % m == p - 1) {
      answer += a[i];
      if (answer.size() == t) break;
    }
  };
  return answer;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << solution(2, 4, 2, 1);

  return 0;
}