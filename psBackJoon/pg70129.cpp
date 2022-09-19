// https://school.programmers.co.kr/learn/courses/30/lessons/70129

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while(s != "1") {
        string tmp = "";
        ++answer[0];
        for (auto si : s) {
            if (si == '1') tmp += "1";
            else ++answer[1];
        }
        
        s = "";
        int num = tmp.size();
        
        while (num != 0) {
            s = s + ((num % 2) ? "1" : "0");
            num /= 2;
        }
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