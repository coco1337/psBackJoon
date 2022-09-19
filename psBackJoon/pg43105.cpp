// https://school.programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<vector<int>> tmp;

int solution(vector<vector<int>> triangle)
{
  vector<int> v(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());

  for (int i = 1; i < triangle.size(); ++i)
  {
    auto idx = triangle.size() - i - 1;

    for (int j = 0; j < triangle[idx].size(); ++j)
    {
      v[j] = max(v[j], v[j + 1]) + triangle[idx][j];
    }
  }


  return v[0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 1; i <= n; ++i)
  {
    vector<int> v(i);
    for (int j = 0; j < i; ++j) cin >> v[j];
    tmp.push_back(v);
  }

  cout << solution(tmp);

  return 0;
}