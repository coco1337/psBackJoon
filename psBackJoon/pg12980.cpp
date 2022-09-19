#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

int t;

int solution(int n)
{
  int ans = 0;

  while (n != 0)
  {
    if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      --n;
      ++ans;
    }
  }

  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;

  cout << solution(t);

  return 0;
}