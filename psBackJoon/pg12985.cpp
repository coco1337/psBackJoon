#include <iostream>
#include <math.h>

using namespace std;

int solution(int n, int a, int b)
{
  int answer = 0;

  for (int i = 1; i <= 20; ++i)
  {
    int t = pow(2, i);
    if ((a - 1) / t == (b - 1) / t) return i;
  }
  return answer;
}

int N, A, B;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> A >> B;
  cout << solution(N, A, B);

  return 0;
}