#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
  int answer = 0;
  sort(citations.begin(), citations.end());
  for (int i = citations.size(); i >= 0; --i)
  {
    if (citations[citations.size() - i] >= i) return i;
  }
  return answer;
}

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  cout << solution(v);

  return 0;
}