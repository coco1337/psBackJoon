// https://school.programmers.co.kr/learn/courses/30/lessons/92335

#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int IsPrime(long long n) {
  if (n < 2) return 0;
  for (long long i = 2; i*i <= n; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int solution(int n, int k) {
  int answer = 0;
  vector<bool> primes;
  vector<long long> nums;
  stack<int> st;

  long long num = 0;
  while (n != 0) {
    auto t = n % k;
    if (t != 0) {
      st.push(t);
    } else {
      num = 0;
      while(!st.empty()) {
        num += st.top() * pow(10, st.size() - 1);
        st.pop();
      }
      if (num > 1)
        nums.push_back(num);
    }

    n /= k;
  }

  num = 0;

  while(!st.empty()) {
    num += st.top() * pow(10, st.size() - 1);
    st.pop();
  }
  if (num > 1)
    nums.push_back(num);

  sort(nums.begin(), nums.end());

  if (nums.size() == 0) return 0;

  for (auto ni : nums) {
    answer += IsPrime(ni);
  }
  return answer;
}
