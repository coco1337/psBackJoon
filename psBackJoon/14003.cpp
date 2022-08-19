#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#include <stack>
#define ll long long int
#define INF 0x3f3f3f3f

using namespace std;

int n;
vector<int> v(1'000'001);
vector<int> dp(1'000'001);
vector<int> lis;
vector<int>::iterator iter;
stack<int> s;
int t, idx;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
    if (lis.size() == 0)
    {
      lis.push_back(v[i]);
      dp[i] = 1;
    }
    else
    {
      if (lis[lis.size() - 1] < v[i])
      {
        lis.push_back(v[i]);
        dp[i] = lis.size();
      }
      else
      {
        iter = lower_bound(lis.begin(), lis.end(), v[i]);
        *iter = v[i];
        dp[i] = iter - lis.begin() + 1;
      }
    }
    if (dp[i] > t)
    {
      idx = i;
      t = dp[i];
    }
  }

  cout << lis.size();
  s.push(v[idx]);
  for (int i = idx - 1; i >= 0; --i)
  {
    if (v[i] < v[idx] && dp[i] + 1 == dp[idx])
    {
      idx = i;
      s.push(v[i]);
    }
  }

  cout << '\n';
  while (!s.empty())
  {
    cout << s.top() << ' ';
    s.pop();
  }

  return 0;
}
