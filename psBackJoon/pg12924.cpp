#include <string>
#include <vector>

using namespace std;

int getSum(int a, int b) {
    int x = 0, y = 0;
    if (a > b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }
    
    return ((x + 1) * x / 2) - ((y + 1) * y / 2);
}

int solution(int n) {
    int answer = 0;
      int r = 1, l = 0;
  while (l != n) {
    int t = getSum(r, l);
    if (t == n) {
      ++answer;
      ++r;
      continue;
    }

    if (t > n) {
      ++l;
    } else {
      ++r;
    }
  }
    
    return answer;
}