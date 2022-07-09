#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v(41);

int n, sum;

int fib(int t)
{
  if (t == 1 || t == 2)
  {
    ++sum;
    return 1;
  }
  else return (fib(t - 1) + fib(t - 2));
}

int fibonacci(int t)
{
  for (int i = 2; i < t; ++i)
  {
    v[i] = v[i - 1] + v[i - 2];
    ++sum;
  }
  return v[t - 1];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  v[0] = 1;
  v[1] = 1;

  sum = 0;
  fib(n);
  cout << sum << " ";
  sum = 0;
  fibonacci(n);
  cout << sum << endl;
  return 0;
}
